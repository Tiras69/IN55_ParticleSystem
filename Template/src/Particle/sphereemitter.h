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

    ParticleTransform * setNewParticleTransform(ParticleTransform * transf);
};

#endif // SPHEREEMITTER_H
