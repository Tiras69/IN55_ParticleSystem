#ifndef TEXTUREDQUAD_H
#define TEXTUREDQUAD_H

#include "SOIL.h"
#include "./Object3D.h"
#include "renderer.h"


class TexturedQuad : public Renderer
{
public:
    TexturedQuad();

private :

    unsigned char * image;
    int imageWidth;
    int imageHeight;

    GLuint texID;
    GLfloat * tabVertices[4*3];
    GLfloat * tabIndices[2*3];
    GLfloat * UVCoordinates[2*3];
};

#endif // TEXTUREDQUAD_H
