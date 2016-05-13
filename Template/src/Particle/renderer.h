#ifndef RENDERER_H
#define RENDERER_H

#include "./Object3D.h"

class Renderer
{
public:
    Renderer();

protected:
    unsigned char * image;
    int imageWidth;
    int imageHeight;
    int channels;

    GLuint texID;
    GLfloat tabVertices[6*3];
    GLuint tabIndices[2*3];
    GLfloat UVCoordinates[6*2];
    GLfloat tabColor[6*3];
};

#endif // RENDERER_H
