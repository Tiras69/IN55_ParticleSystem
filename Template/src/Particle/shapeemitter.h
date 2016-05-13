#ifndef SHAPEEMITTER_H
#define SHAPEEMITTER_H

#include "Vectors.h"
#include "particletransform.h"

class ShapeEmitter
{
public:
    ShapeEmitter();

    Vec3 position;

    virtual ParticleTransform * getNewParticleTransform()=0;

};

#endif // SHAPEEMITTER_H
