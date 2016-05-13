#include "sphereemitter.h"

SphereEmitter::SphereEmitter()
{
    position = Vec3(0.0f, 0.0f, 0.0f);
    srand(time(NULL));
    radius = 1.0f;
}

SphereEmitter::SphereEmitter(float rad):SphereEmitter(){
    radius = rad;
}

ParticleTransform *
SphereEmitter::getNewParticleTransform(){
    float x = ((fmod(rand() ,radius * 2)) - radius);
    float y = ((fmod(rand() ,radius * 2)) - radius);
    float z = ((fmod(rand() ,radius * 2)) - radius);
    Vec3 direction = Vec3(x, y, z);
    Vec3 pos = position + direction;
    direction.normalize();

    return new ParticleTransform(pos, direction, 1.0f);

}
