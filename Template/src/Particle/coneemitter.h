#ifndef CONEEMITTER_H
#define CONEEMITTER_H

#include "shapeemitter.h"

#include <stdlib.h>
#include <time.h>

class ConeEmitter : public ShapeEmitter
{
public:
    ConeEmitter(float downRadius, float upRadius, float height);
    ParticleTransform * setNewParticleTransform(ParticleTransform * transf);

private:

    float m_downRadius;
    float m_upRadius;
    float m_height;



};

#endif // CONEEMITTER_H
