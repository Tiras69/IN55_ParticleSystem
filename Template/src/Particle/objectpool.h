#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "particletransform.h"
#include <vector>

class ObjectPool
{
public:
    ObjectPool(int n);

    ParticleTransform* getObject();


private :
    int ObjectNumber;
    std::vector<ParticleTransform> objects;
};

#endif // OBJECTPOOL_H
