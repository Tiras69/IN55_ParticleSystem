#ifndef SHAPEEMITTER_H
#define SHAPEEMITTER_H

#include "Vectors.h"
#include "particletransform.h"

class ShapeEmitter
{
public:
    ShapeEmitter();

    Vec3 position;

    virtual ParticleTransform * setNewParticleTransform(ParticleTransform * transf)=0;

};

#endif // SHAPEEMITTER_H
