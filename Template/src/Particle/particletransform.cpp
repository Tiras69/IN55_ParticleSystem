#include "particletransform.h"

#include <iostream>
// <3
ParticleTransform::ParticleTransform(Vec3 _initPos, Vec3 _direction, float _speed, Camera * _camera)
{

    camera = _camera;
    isEnable = false;
    lifeTime = 5.0f;
    currentLifeTime = 0.0f;
    initialPosition = _initPos;
    position = _initPos;
    direction = _direction;
    speed = _speed;
    distance = -1.0f;

}

void ParticleTransform::Update(float deltaTime){
    currentLifeTime += deltaTime;

    if(currentLifeTime > lifeTime){
        Pause();
    }

    if(isEnable){
        //std::cout << "gravity : " << m_gravity << std::endl;
        direction = direction + (Vec3(0.0f, -m_gravity, 0.0f) * deltaTime);
        position = position + (direction * deltaTime * speed);

        calculateDistance();


        ModelMatrix.m[0][0] = 1.0f; ModelMatrix.m[0][1] = 0.0f; ModelMatrix.m[0][2] = 0.0f; ModelMatrix.m[0][3] = position.x;
        ModelMatrix.m[1][0] = 0.0f; ModelMatrix.m[1][1] = 1.0f; ModelMatrix.m[1][2] = 0.0f; ModelMatrix.m[1][3] = position.y;
        ModelMatrix.m[2][0] = 0.0f; ModelMatrix.m[2][1] = 0.0f; ModelMatrix.m[2][2] = 1.0f; ModelMatrix.m[2][3] = position.z;
        ModelMatrix.m[3][0] = 0.0f; ModelMatrix.m[3][1] = 0.0f; ModelMatrix.m[3][2] = 0.0f; ModelMatrix.m[3][3] = 1.0f;
    }
}

void ParticleTransform::setLifeTime(float time){
    lifeTime = time;
}

void ParticleTransform::Start(Vec3 _initPos, Vec3 _direction, float _speed, float _gravity){
    isEnable = true;
    currentLifeTime = 0.0f;

    initialPosition = _initPos;
    position = initialPosition;
    calculateDistance();

    direction = _direction;
    speed = _speed;
    //std::cout << "gravity : " << m_gravity << std::endl;
    m_gravity = _gravity;
}

void ParticleTransform::Pause(){
    isEnable = false;
    distance = -1.0f;
}

void
ParticleTransform::calculateDistance(){
    float x = camera->getPosition().x - position.x;
    float y = camera->getPosition().y - position.y;
    float z = camera->getPosition().z - position.z;

    distance = x*x + y*y + z*z;
}

bool
ParticleTransform::operator <(const ParticleTransform & transf) const{
    return (distance > transf.distance);
}
