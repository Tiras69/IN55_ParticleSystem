#include "objectpool.h"

ObjectPool::ObjectPool(int n, Camera * _camera)
{
    objects = std::vector<ParticleTransform>();
    ObjectNumber = n;
    camera = _camera;

    for(int i = 0 ; i < n ; i++){
        objects.push_back(ParticleTransform(
                                                Vec3(0.0f,
                                                     0.0f,
                                                     0.0f
                                                     ),
                                                Vec3(1.0f,
                                                     1.0f,
                                                     0.0f
                                                     ),
                                                2.0f,
                                                camera
                                                )
                          );

    }
    LastIt = objects.begin();
}


// In this function we return the first object to be
// disabled.
ParticleTransform* ObjectPool::getObject(){
    std::vector<ParticleTransform>::iterator it;

    for(it = LastIt ; it != objects.end() ; it++){
        if(!(*it).isEnable){
            LastIt = it;
            return &(*it);
        }
    }

    for(it = objects.begin() ; it != objects.end() ; it++){
        if(!(*it).isEnable){
            LastIt = it;
            return &(*it);
        }
    }

    return NULL;
}
