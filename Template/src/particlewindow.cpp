#include "particlewindow.h"
#include "Particle/particletransform.h"
#include "Particle/sphereemitter.h"

#include <unistd.h>
#include <iostream>

using namespace std;

//ParticleTransform * ref_transf;
//SphereEmitter * sphereEmitter;

ParticleWindow::ParticleWindow()
{
    camera = new Camera(00.0f, 5.0f, 30.0f, 4.0f/3.0f, 0.3f, 1000.0f, 60.0f);
    particleSystem = new ParticleSystem(new SphereEmitter(10.0f),
                                        100000,
                                        1000.0f,
                                        new TexturedQuad(),
                                        camera);
    //quad = new TexturedQuad();

    //pool = new ObjectPool(1, camera);

    //sphereEmitter = new SphereEmitter(2.0f);

    //ref_transf = pool->getObject();
    //sphereEmitter->setNewParticleTransform(ref_transf);


    timeStart = clock();
}

ParticleWindow::~ParticleWindow(){
    delete camera;
    //delete quad;
    //delete pool;
}

void ParticleWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            //quad->opacity += 0.1f;
            break;
        case Qt::Key_Down:
            //quad->opacity -= 0.1f;
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


    //lookAt(0, 5, -30, 0, 0, 0);
    pViewMatrix = camera->getViewMatrix();
    pProjMatrix = camera->getProjectionMatrix();

    pushMatrix();

        std::vector<ParticleTransform>::iterator iterator;
        particleSystem->Update(frameRate);

        // We sort the particules:
        std::sort(particleSystem->pool->objects.begin(), particleSystem->pool->objects.end());


        particleSystem->renderer->initGLFrame();
        for(iterator = particleSystem->pool->objects.begin() ; iterator != particleSystem->pool->objects.end(); iterator++){
            //std::cout << "distance : " << (*iterator).distance << std::endl;
            if((*iterator).isEnable){
                (*iterator).Update(frameRate);
                pushMatrix();
                    addCustomTransform((*iterator).ModelMatrix);
                    //std::cout << "pos : " << (*iterator).position.x << " " << (*iterator).position.y << " " << (*iterator).position.z << std::endl;
                    particleSystem->renderer->draw();
                popMatrix();
            }
        }
        particleSystem->renderer->closeGLFrame();


//        addCustomTransform(ref_transf->ModelMatrix);

//        if(ref_transf->isEnable){
//            quad->draw();
//        }else{

//            sphereEmitter->setNewParticleTransform(ref_transf);

//            //ref_transf = sphereEmitter->getNewParticleTransform();
//            //ref_transf->Start();
//        }

//        ref_transf->Update(1.0f/30.f);
    popMatrix();

    timeEnd = clock();
    clock_t frameTime = timeEnd - timeStart;
    //float frameRate = 1.0f / 30.0f;
    float framefTime = ((float)frameTime) / CLOCKS_PER_SEC;

    if(framefTime < frameRate)
        usleep((frameRate - framefTime) * 1000000);
}


