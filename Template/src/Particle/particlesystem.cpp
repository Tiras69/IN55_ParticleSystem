#include "particlesystem.h"

ParticleSystem::ParticleSystem(ShapeEmitter * _emitter, int numberParticles,float emitRate, TexturedQuad * _renderer, Camera * _cam)
{
    emitter = _emitter;
    camera = _cam;
    pool = new ObjectPool(numberParticles, camera);
    EmitRate = emitRate;
    renderer = _renderer;
    timer = 0.0f;
}

ParticleSystem::~ParticleSystem(){
    delete emitter;
    delete pool;
    delete renderer;

}

void
ParticleSystem::Update(float deltaTime){
    timer = timer + deltaTime;

    // In this part we want to define the number of particle
    // that we have to instanciate in this Frame.
    float div = timer/ (1/EmitRate);

    //std::cout << div << " = " << timer << " / " << EmitRate << std::endl;

    if(div >= 1.0f){
        int nbPart = (int)div;
        timer -= nbPart * (1 / EmitRate);
        for(int i=0 ; i < nbPart ; i++){
            emitter->setNewParticleTransform(pool->getObject());
        }
    }

}

//void
//ParticleSystem::drawShape(){

//    // Draw the renderer .


//}

//void
//ParticleSystem::initGLFrame(){
//    //TODO: Put the things that are in QuadRenderer
//}

//void
//ParticleSystem::closeGLFrame(){
//    //TODO: Put the things that are in QuadRenderer
//}
