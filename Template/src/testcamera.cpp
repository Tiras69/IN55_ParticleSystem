#include "testcamera.h"

using namespace std;

TestCamera::TestCamera(){
    cam1 = new Camera(00.0f, 5.0f, 30.0f, 4.0f/3.0f, 0.3f, 1000.0f, 60.0f);
    incredibleCubeTest = new Cube(1.0f, 1000.0f, 1.0f);
}

TestCamera::~TestCamera(){
    delete cam1;
    delete incredibleCubeTest;
}

bool TestCamera::initializeObjects(){
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

void TestCamera::render(){
    //lookAt(0, 5,30, 0, 0, 0);

    pViewMatrix = cam1->getViewMatrix();
    pProjMatrix = cam1->getProjectionMatrix();

    pushMatrix();
        incredibleCubeTest->draw();
        translate(5.0f, 0.0f, 0.0f);
        incredibleCubeTest->draw();
        translate(-10.0f, 0.0f, 0.0f);
        incredibleCubeTest->draw();
    popMatrix();

}

void TestCamera::mouseMoveEvent(QMouseEvent *event){
    cout << "YEY SOURIS : " << event->globalX() << " " << event->globalY() << endl;
}

void TestCamera::keyPressEvent(QKeyEvent * event){
    switch( event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            cam1->translateX(1.0f);
            angle1 -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            cam1->translateX(-1.0f);
            angle1 += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            cam1->rotateX(-(M_PI / 4.0f));
            angle2 -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            cam1->rotateX(M_PI / 4.0f);
            angle2 += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
    }
}
