#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Object3D.h"
#include "objectpool.h"
#include "shapeemitter.h"
#include "renderer.h"

class ParticleSystem : public Object3D
{
public:
    ParticleSystem();
    ~ParticleSystem();

private:
    ShapeEmitter * emitter;
    ObjectPool * pool;
    Renderer * renderer;
    void drawShape();
};

#endif // PARTICLESYSTEM_H
