#ifndef CYLINDER_H
#define CYLINDER_H

#include <math.h>
#include <stdlib.h>
#include "Object3D.h"

class Cylinder: public Object3D
{
public:
    Cylinder(int nbSides, float radius, float heigth);
    ~Cylinder();

protected:
    void drawShape();

    GLfloat *m_TabVertices;
    GLfloat *m_TabColors;

    GLuint *m_TabIndicesCircleOne;
    GLuint *m_TabIndicesCircleTwo;
    GLuint *m_TabIndicesSide;

    int nbIndices;
    int nbIndicesSide;
};

#endif // CYLINDER_H
