#ifndef PARTICLETRANSFORM_H
#define PARTICLETRANSFORM_H

#include "GlFramework.h"
#include "Vectors.h"

class ParticleTransform
{
public:
    ParticleTransform();

    Vec3 position;
    Vec3 * CameraPosition;
    GLMatrix ModelMatrix;
};

#endif // PARTICLETRANSFORM_H
