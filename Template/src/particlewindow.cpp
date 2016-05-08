#include "particlewindow.h"

#include <iostream>

using namespace std;

ParticleWindow::ParticleWindow()
{
    cout << "yey" << endl;
    quad = new TexturedQuad();
    cout << "yey" << endl;
}

ParticleWindow::~ParticleWindow(){
    delete quad;
}

void ParticleWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            quad->opacity += 0.1f;
            break;
        case Qt::Key_Down:
            quad->opacity -= 0.1f;
            break;

    }
}

bool ParticleWindow::initializeObjects(){

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


void ParticleWindow::render(){

    lookAt(0, 5, -30, 0, 0, 0);


    pushMatrix();
        quad->draw();
        //translate(0.0f, 0.0f, 10.0f);
        //quad->draw();
    popMatrix();
}


