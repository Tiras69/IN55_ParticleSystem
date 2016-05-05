#include "TP01.h"


#include "Shapes/Basis.h"
#include "Shapes/cylinder.h"
#include "Shapes/Cube.h"

#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

double deltaTime;
clock_t end;
clock_t start;

Basis* g_Basis;
Cube * Tete;
Cube * Torse;
Cube * BrasDroit;
Cube * BrasGauche;
Cube * JambeDroite;
Cube * JambeGauche;


TP01::TP01()
{
	setWindowTitle(trUtf8("IN55-TP01"));

    g_Basis = new Basis( 10.0 );

    Tete = new Cube(2.0f, 2.0f, 2.0f);
    Torse = new Cube(3.0f, 5.0f, 2.0f);
    BrasDroit = new Cube(1.0f, 4.0f, 1.0f);
    BrasGauche = new Cube(1.0f, 4.0f, 1.0f);
    JambeDroite = new Cube(1.0f, 5.0f, 1.0f);
    JambeGauche = new Cube(1.0f, 5.0f, 1.0f);

    start = clock();
}


TP01::~TP01()
{
    delete g_Basis;
    delete Tete;
    delete Torse;
    delete BrasDroit;
    delete BrasGauche;
    delete JambeDroite;
    delete JambeGauche;
}


bool
TP01::initializeObjects()
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

float degrePerSecond = 180.0f;
float currentAngle = 0.0f;
bool negatif = false;

void
TP01::render()
{

    deltaTime = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    start = clock();

    std::cout << deltaTime << std::endl;

    if(negatif)
        currentAngle -= degrePerSecond * deltaTime *10;
    else
        currentAngle += degrePerSecond * deltaTime *10;

    if(currentAngle < -30.0f){
        currentAngle = -30.0f;
        negatif = false;
    }

    if(currentAngle > 30.0f){
        currentAngle = 30.0f;
        negatif = true;
    }

	// Initialisation de la caméra
	lookAt( 0, 5, 30, 0, 0, 0 );


	// Rendu des objets
	pushMatrix();
		rotate( angle1, 0, 1, 0 );
		rotate( angle2, 1, 0, 0 );
        g_Basis->draw();

        pushMatrix();
            translate(0.0f, 3.5f, 0.0f);
            Tete->draw();
        popMatrix();

        pushMatrix();
            rotate(currentAngle, 0.0f, 1.0f, 0.0f);
            Torse->draw();

            pushMatrix();
                translate(2.0f, -0.5f, 0.0f);
                translate(0.0f, 2.0f, 0.0f);
                rotate(-currentAngle, 1.0f, 0.0f, 0.0f);
                translate(0.0f, -2.0f, 0.0f);
                BrasDroit->draw();
            popMatrix();

            pushMatrix();
                translate(-2.0f, -0.5f, 0.0f);
                translate(0.0f, 2.0f, 0.0f);
                rotate(currentAngle, 1.0f, 0.0f, 0.0f);
                translate(0.0f, -2.0f, 0.0f);
                BrasGauche->draw();
            popMatrix();

        popMatrix();

        pushMatrix();
            translate(1.0f, -5.0f, 0.0f);
            translate(0.0f, 2.5f, 0.0f);
            rotate(-currentAngle, 1.0f, 0.0f, 0.0f);
            translate(0.0f, -2.5f, 0.0f);
            JambeDroite->draw();
        popMatrix();

        pushMatrix();
            translate(-1.0f, -5.0f, 0.0f);
            translate(0.0f, 2.5f, 0.0f);
            rotate(currentAngle, 1.0f, 0.0f, 0.0f);
            translate(0.0f, -2.5f, 0.0f);
            JambeGauche->draw();
        popMatrix();


	popMatrix();

    end = clock();
}


void
TP01::keyPressEvent( QKeyEvent* event )
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
