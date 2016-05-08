#ifndef TEXTUREDQUAD_H
#define TEXTUREDQUAD_H

#include "SOIL.h"
#include "./Object3D.h"
#include "renderer.h"


class TexturedQuad : public Object3D
{
public:
    TexturedQuad();

    GLfloat opacity;
protected:
    void drawShape();



private :

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

#endif // TEXTUREDQUAD_H
