#ifndef PARTICLETRANSFORM_H
#define PARTICLETRANSFORM_H

#include "GlFramework.h"
#include "Vectors.h"

class ParticleTransform
{

public:
    ParticleTransform(Vec3 _initPos, Vec3 _direction, float _speed);

    bool isEnable;
    float lifeTime;
    float currentLifeTime;

    Vec3 initialPosition;
    Vec3 direction;
    float speed;

    Vec3 position;
    Vec3 * CameraPosition;
    GLMatrix ModelMatrix;

    void Update(float deltaTime);
    void setLifeTime(float time);
    void Start();
    void Pause();
};

#endif // PARTICLETRANSFORM_H
