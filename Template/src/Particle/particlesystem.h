#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Object3D.h"
#include "objectpool.h"
#include "shapeemitter.h"
#include "renderer.h"
#include "camera.h"
#include "texturedquad.h"

#include <cmath>

class ParticleSystem /*: public Object3D*/
{
public:
    ParticleSystem(ShapeEmitter * _emitter, int numberParticles,float emitRate, TexturedQuad * _renderer, Camera * _cam);
    ~ParticleSystem();

    ShapeEmitter * emitter;
    ObjectPool * pool;
    TexturedQuad * renderer;
    Camera * camera;

    float EmitRate;
    float timer;

    void Update(float deltaTime);
    /*void drawShape();
    void initGLFrame();
    void closeGLFrame();*/
};

#endif // PARTICLESYSTEM_H
