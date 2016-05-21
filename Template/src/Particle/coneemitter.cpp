#include "coneemitter.h"

ConeEmitter::ConeEmitter(float downRadius, float upRadius, float height, float spawnHeight)
{
    // Init the random seed.
    srand(time(NULL));
}

ParticleTransform *
ConeEmitter::setNewParticleTransform(ParticleTransform * transf){
    // We compute the original position.
    // one position on the down circle
    float theta = fmod( rand(), (2 * M_PI));
    float x = cos(theta);
    float y = sin(theta);

    // Now we get a percentage random
}
