#include "particlewindow.h"
#include "Particle/particletransform.h"
#include "Particle/sphereemitter.h"
#include "Particle/coneemitter.h"

#include <unistd.h>
#include <iostream>

using namespace std;


ParticleWindow::ParticleWindow()
{
    camera = new Camera(00.0f, 0.0f, 100.0f, 4.0f/3.0f, 0.3f, 1000.0f, 60.0f);
    particleSystem = new ParticleSystem(new ConeEmitter(1.0f, 10.0f, 20.0f),
                                        100000,
                                        1000.0f,
                                        new TexturedQuad(),
                                        camera);

    isForwardPressed = false;
    isLeftPressed = false;
    isRightPressed = false;
    isDownPressed = false;


    timeStart = clock();

    QCursor::setPos(this->geometry().x() + (this->geometry().width() / 2.0f),
                    this->geometry().y() + (this->geometry().height() / 2.0f) );
    lastMousePostion = Vec2((float)QCursor::pos().x(), (float)QCursor::pos().y());


}

ParticleWindow::~ParticleWindow(){
    delete camera;
}


void ParticleWindow::keyPressEvent(QKeyEvent *event){
    if(!isForwardPressed && (event->key() == Qt::Key_Up || event->key() == Qt::Key_Z)){
        isForwardPressed = true;
    }
    if(!isLeftPressed && (event->key() == Qt::Key_Left || event->key() == Qt::Key_Q)){
        isLeftPressed = true;
    }
    if(!isRightPressed && (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)){
        isRightPressed = true;
    }
    if(!isDownPressed && (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)){
        isDownPressed = true;
    }
    if(event->key() == Qt::Key_Escape)
        this->close();
    if(event->key() == Qt::Key_G)
        camera->rotateY(M_PI / 2.0f);
}

void ParticleWindow::keyReleaseEvent(QKeyEvent *event){
    if(isForwardPressed && (event->key() == Qt::Key_Up || event->key() == Qt::Key_Z)){
        isForwardPressed = false;
    }
    if(isLeftPressed && (event->key() == Qt::Key_Left || event->key() == Qt::Key_Q)){
        isLeftPressed = false;
    }
    if(isRightPressed && (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)){
        isRightPressed = false;
    }
    if(isDownPressed && (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)){
        isDownPressed = false;
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

    pViewMatrix = camera->getViewMatrix();
    pProjMatrix = camera->getProjectionMatrix();

    //Vec3 camDirVect = Vec3(0.0f, 0.0f, 0.0f);
    // Update Camera.

    if(isForwardPressed)
        camera->translateZ(cameraSpeed * frameRate);
    if(isRightPressed)
        camera->translateX(-cameraSpeed * frameRate);
    if(isLeftPressed)
        camera->translateX(cameraSpeed * frameRate);
    if(isDownPressed)
        camera->translateZ(-cameraSpeed * frameRate);


    Vec2 currentMousePosition;
    if(this->geometry().contains(QCursor::pos()))
        currentMousePosition = Vec2((float)QCursor::pos().x(), (float)QCursor::pos().y());
    else
        currentMousePosition = lastMousePostion;

    float mDirx = lastMousePostion.x - currentMousePosition.x;
    float mDiry = lastMousePostion.y - currentMousePosition.y;


    camera->rotateX(mDiry * mouseSensibility * frameRate);
    camera->rotateY(mDirx * mouseSensibility * frameRate);

    /*camera->rotate(mDiry * mouseSensibility * frameRate,
                   camera->right.x,
                   camera->right.y,
                   camera->right.z);*/



    lastMousePostion = currentMousePosition;


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


