#ifndef CUBE_H
#define CUBE_H

#include "Object3D.h"

class Cube : public Object3D{
 public:
    Cube(GLfloat x, GLfloat y, GLfloat z);
    Cube(GLfloat length);
    ~Cube();
protected:
    void drawShape();

    GLfloat m_TabVertices[8*3]; // size 8vertex*3coordonées
    GLfloat m_TabColors[8*3]; // size 8vertex*3coordonées
    GLuint m_TabIndices[6*2*3]; // 6 faces * 2 triangles * 3 points
};

#endif // CUBE_H
