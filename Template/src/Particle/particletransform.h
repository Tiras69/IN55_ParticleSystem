#ifndef PARTICLETRANSFORM_H
#define PARTICLETRANSFORM_H

#include <time.h>
#include <stdlib.h>
#include "GlFramework.h"
#include "Vectors.h"
#include "camera.h"


class ParticleTransform
{

public:
    ParticleTransform(Vec3 _initPos, Vec3 _direction, float _speed, Camera * _camera);

    void calculateDistance();
    bool operator < (const ParticleTransform & transf) const;

    void Update(float deltaTime);
    void setLifeTime(float time);
    void Start(Vec3 _initPos, Vec3 _direction, float _speed, float _gravity);
    void Pause();

    bool isEnable;
    float lifeTime;
    float currentLifeTime;

    Vec3 initialPosition;
    Vec3 direction;
    float speed;
    float distance;
    float torque;
    float currentRotationZ;

    Vec3 position;
    Camera * camera;
    GLMatrix ModelMatrix;

private:

    float m_gravity;
};

#endif // PARTICLETRANSFORM_H
