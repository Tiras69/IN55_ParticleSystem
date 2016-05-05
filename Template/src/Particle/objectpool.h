#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <vector>

template<typename T>
class ObjectPool
{
public:
    ObjectPool(int n);

    T getObject();
    void disableObject(int n);

private :
    int ObjectNumber;
    std::vector<T>  objects;
    std::vector<bool>  enabledVect;
};

#endif // OBJECTPOOL_H
