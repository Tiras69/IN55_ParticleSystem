#include "particletransform.h"

#include <iostream>
// <3
ParticleTransform::ParticleTransform(Vec3 _initPos, Vec3 _direction, float _speed)
{


    isEnable = false;
    lifeTime = 5.0f;
    currentLifeTime = 0.0f;
    initialPosition = _initPos;
    position = _initPos;
    direction = _direction;
    speed = _speed;


}

void ParticleTransform::Update(float deltaTime){
    currentLifeTime += deltaTime;

    if(currentLifeTime > lifeTime){
        Pause();
    }

    if(isEnable){
        position = position + (direction * deltaTime * speed);

        //std::cout << deltaTime << " " << direction.x <<" " << direction.y <<" " << direction.z  << std::endl;

        ModelMatrix.m[0][0] = 1.0f; ModelMatrix.m[0][1] = 0.0f; ModelMatrix.m[0][2] = 0.0f; ModelMatrix.m[0][3] = position.x;
        ModelMatrix.m[1][0] = 0.0f; ModelMatrix.m[1][1] = 1.0f; ModelMatrix.m[1][2] = 0.0f; ModelMatrix.m[1][3] = position.y;
        ModelMatrix.m[2][0] = 0.0f; ModelMatrix.m[2][1] = 0.0f; ModelMatrix.m[2][2] = 1.0f; ModelMatrix.m[2][3] = position.z;
        ModelMatrix.m[3][0] = 0.0f; ModelMatrix.m[3][1] = 0.0f; ModelMatrix.m[3][2] = 0.0f; ModelMatrix.m[3][3] = 1.0f;
    }
}

void ParticleTransform::setLifeTime(float time){
    lifeTime = time;
}

void ParticleTransform::Start(){
    isEnable = true;
    currentLifeTime = 0.0f;
    position = initialPosition;
}

void ParticleTransform::Pause(){
    isEnable = false;

}
