#include "coneemitter.h"

ConeEmitter::ConeEmitter(float downRadius, float upRadius, float height, float _speed, float _gravity)
{
    m_downRadius = downRadius;
    m_upRadius = upRadius;
    m_height = height;
    particuleSpeed = _speed;
    gravity = _gravity;
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

    // Now we get a random percentage
    float percentage = fmod(rand(), 100.0f);

    Vec3 initPos = Vec3(x, 0.0f, y);
    initPos.normalize();
    initPos *= (percentage*m_downRadius/100.0f);

    Vec3 dirVect = Vec3(x, 0.0f, y);
    dirVect.normalize();
    dirVect *= (percentage*m_upRadius/100.0f);
    dirVect.y = m_height;

    dirVect = dirVect - initPos;
    dirVect.normalize();

    transf->Start(initPos, dirVect, particuleSpeed, gravity);

    return transf;
}
