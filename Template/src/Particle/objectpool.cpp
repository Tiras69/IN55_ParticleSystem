#include "objectpool.h"

ObjectPool::ObjectPool(int n)
{
    objects = std::vector<ParticleTransform>();
    ObjectNumber = n;

    for(int i = 0 ; i < n ; i++){
        objects.push_back(ParticleTransform(Vec3(0.0f, 0.0f, 0.0f),
                                            Vec3(1.0f, 1.0f, 0.0f),
                                            1.0f));
    }
}

ParticleTransform* ObjectPool::getObject(){
    std::vector<ParticleTransform>::iterator it;
    for(it = objects.begin() ; it != objects.end() ; it++){
        if(!(*it).isEnable){
            return &(*it);
        }
    }

    return NULL;
}
