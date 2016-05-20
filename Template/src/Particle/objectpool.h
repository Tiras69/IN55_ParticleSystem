#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "particletransform.h"
#include <vector>

class ObjectPool
{
public:
    ObjectPool(int n, Camera * _camera);

    ParticleTransform* getObject();

    std::vector<ParticleTransform>::iterator LastIt;
    std::vector<ParticleTransform> objects;

private :
    Camera * camera;
    int ObjectNumber;


};

#endif // OBJECTPOOL_H
