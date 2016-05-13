#include "particlewindow.h"
#include "Particle/particletransform.h"

#include <unistd.h>
#include <iostream>

using namespace std;

ParticleTransform * ref_transf;

ParticleWindow::ParticleWindow()
{
    quad = new TexturedQuad();

    pool = new ObjectPool(1);



    ref_transf = pool->getObject();
    ref_transf->Start();
    timeStart = clock();
}

ParticleWindow::~ParticleWindow(){
    delete quad;
    delete pool;
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
    timeStart = clock();

    //frameTime = clock();
    //float deltaTime = ((float)timeEnd - timeStart) / CLOCKS_PER_SEC;


    //std::cout << " TIME : " << deltaTime << std::endl;

    lookAt(0, 5, -30, 0, 0, 0);

    pushMatrix();

        //std::cout << "POSITION : " << ref_transf->position.x << " " << ref_transf->position.y << " " << ref_transf->position.z << std::endl;
        addCustomTransform(ref_transf->ModelMatrix);
        if(ref_transf->isEnable)
            quad->draw();
        else
            ref_transf->Start();

        ref_transf->Update(1.0f/30.f);
    popMatrix();

    timeEnd = clock();
    clock_t frameTime = timeEnd - timeStart;
    float frameRate = 1.0f / 30.0f;
    float framefTime = ((float)frameTime) / CLOCKS_PER_SEC;

    if(framefTime < frameRate)
        usleep((frameRate - framefTime) * 1000000);
}


