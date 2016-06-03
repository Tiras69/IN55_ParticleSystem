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
SphereEmitter::setNewParticleTransform(ParticleTransform * transf){
    //std::cout << "new Particle ? " << transf << std::endl;

    float x = ((fmod(rand() ,radius * 2.0f )) - radius );
    float y = ((fmod(rand() ,radius * 2.0f )) - radius );
    float z = ((fmod(rand() ,radius * 2.0f )) - radius );
    Vec3 direction = Vec3(x, y, z);
    Vec3 pos = position + direction;
    direction.normalize();
    //std::cout << "dir " << direction.x << " " << direction.y << " " << direction.z << std::endl;

    transf->Start(pos, direction, 4.0f, 1.5f);

    return transf;

}
