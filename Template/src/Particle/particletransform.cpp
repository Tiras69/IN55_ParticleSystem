#include "particletransform.h"

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

    currentRotationZ = 0.0f;

    torque = fmod( rand() , 4.0f * M_PI ) - (2.0f * M_PI);



}

void ParticleTransform::Update(float deltaTime){
    currentLifeTime += deltaTime;

    if(currentLifeTime > lifeTime){
        Pause();
    }

    if(isEnable){
        direction = (direction * speed  + Vec3(0.0f, -m_gravity, 0.0f)) * deltaTime;
        position = position + direction;

        currentRotationZ += torque * deltaTime ;

        calculateDistance();

        float * tmpMatRot = new float[16];
        // Get the rotation Matrix from the Quaternion.
        camera->m_Orientation.setRotationMatrix(tmpMatRot);

        GLMatrix m_ViewMatrix = GLMatrix();
        m_ViewMatrix.m[0][0] = tmpMatRot[0] ; m_ViewMatrix.m[0][1] = tmpMatRot[4] ; m_ViewMatrix.m[0][2] = tmpMatRot[8] ; m_ViewMatrix.m[0][3] = tmpMatRot[12] ;
        m_ViewMatrix.m[1][0] = tmpMatRot[1] ; m_ViewMatrix.m[1][1] = tmpMatRot[5] ; m_ViewMatrix.m[1][2] = tmpMatRot[9] ; m_ViewMatrix.m[1][3] = tmpMatRot[13] ;
        m_ViewMatrix.m[2][0] = tmpMatRot[2] ; m_ViewMatrix.m[2][1] = tmpMatRot[6] ; m_ViewMatrix.m[2][2] = tmpMatRot[10] ; m_ViewMatrix.m[2][3] = tmpMatRot[14] ;
        m_ViewMatrix.m[3][0] = tmpMatRot[3] ; m_ViewMatrix.m[3][1] = tmpMatRot[7] ; m_ViewMatrix.m[3][2] = tmpMatRot[11] ; m_ViewMatrix.m[3][3] = tmpMatRot[15] ;

        delete tmpMatRot;

        GLMatrix rotMatrix = GLMatrix();
        rotMatrix.m[0][0] = cos(currentRotationZ) ; rotMatrix.m[0][1] = -sin(currentRotationZ) ; rotMatrix.m[0][2] = 0.0f ; rotMatrix.m[0][3] = 0.0f ;
        rotMatrix.m[1][0] = sin(currentRotationZ) ; rotMatrix.m[1][1] = cos(currentRotationZ)  ; rotMatrix.m[1][2] = 0.0f ; rotMatrix.m[1][3] = 0.0f ;
        rotMatrix.m[2][0] = 0.0f                  ; rotMatrix.m[2][1] = 0.0f                   ; rotMatrix.m[2][2] = 1.0f ; rotMatrix.m[2][3] = 0.0f ;
        rotMatrix.m[3][0] = 0.0f                  ; rotMatrix.m[3][1] = 0.0f                   ; rotMatrix.m[3][2] = 0.0f ; rotMatrix.m[3][3] = 1.0f ;

        ModelMatrix.m[0][0] = 1.0f; ModelMatrix.m[0][1] = 0.0f; ModelMatrix.m[0][2] = 0.0f; ModelMatrix.m[0][3] = position.x;
        ModelMatrix.m[1][0] = 0.0f; ModelMatrix.m[1][1] = 1.0f; ModelMatrix.m[1][2] = 0.0f; ModelMatrix.m[1][3] = position.y;
        ModelMatrix.m[2][0] = 0.0f; ModelMatrix.m[2][1] = 0.0f; ModelMatrix.m[2][2] = 1.0f; ModelMatrix.m[2][3] = position.z;
        ModelMatrix.m[3][0] = 0.0f; ModelMatrix.m[3][1] = 0.0f; ModelMatrix.m[3][2] = 0.0f; ModelMatrix.m[3][3] = 1.0f;

        ModelMatrix = ModelMatrix  * m_ViewMatrix * rotMatrix;
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
