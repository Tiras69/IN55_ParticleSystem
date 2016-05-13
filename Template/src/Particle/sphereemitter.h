#ifndef SPHEREEMITTER_H
#define SPHEREEMITTER_H

#include "shapeemitter.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

class SphereEmitter : public ShapeEmitter
{
public:
    SphereEmitter();
    SphereEmitter(float rad);
    float radius;

    ParticleTransform * getNewParticleTransform();
};

#endif // SPHEREEMITTER_H
