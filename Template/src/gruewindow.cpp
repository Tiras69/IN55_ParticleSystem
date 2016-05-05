#include "gruewindow.h"



#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;



GrueWindow::GrueWindow()
{
    setWindowTitle(trUtf8("IN55-TP02"));

    basis = new Basis( 10.0 );
    cube1 = new Cube(L3, H4, P1);
    cube2 = new Cube(L2, H2, P1);
    cube3 = new Cube(L1, H2, P1);
    cyl1 = new Cylinder(20, 1.0f, H3);
    cyl2 = new Cylinder(20, 0.5f, H3);
}

GrueWindow::~GrueWindow(){
    delete basis;
    delete cube1;
    delete cube2;
    delete cube3;
    delete cyl1;
    delete cyl2;
}

void GrueWindow::render(){
    lookAt( 0, 5, 30, 0, 0, 0 );
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );

        basis->draw();

        pushMatrix();
            translate(0.0f, H4 / 2.0f , 0.0f);
            cube1->draw();
            pushMatrix();
                translate(0.0f, (H4 / 2.0f) + (H3 / 2.0f), 0.0f);
                cyl1->draw();
                pushMatrix();
                    translate(0.0f, (H3 / 2.0f) + (H2 / 2.0f), 0.0f );
                    cube2->draw();
                    pushMatrix();
                        translate((L2 / 2.0f) - (L1 / 2.0f), -H2, 0.0f );
                        cube3->draw();
                    popMatrix();
                    pushMatrix();
                        translate( -(L2 / 2.0f) , - ((H2/2.0f) +(H3))  / 2.0f, 0.0f);
                        cyl2->draw();
                    popMatrix();
                popMatrix();
            popMatrix();
        popMatrix();


    popMatrix();
}

bool GrueWindow::initializeObjects()
{

    // Fond gris
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    // Chargement des shaders
    createShader( "Shaders/color" );

    cout << "Shader color: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    return true;
}

void GrueWindow::keyPressEvent( QKeyEvent* event )
{
    switch( event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            angle1 -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
    }
}
