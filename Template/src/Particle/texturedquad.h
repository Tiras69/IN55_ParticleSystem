#ifndef TEXTUREDQUAD_H
#define TEXTUREDQUAD_H

#include "SOIL.h"
#include "./Object3D.h"
#include "renderer.h"


class TexturedQuad : public Renderer, public Object3D
{
public:
    TexturedQuad();

    GLfloat opacity;

    void initGLFrame();

    void closeGLFrame();
protected:
    void drawShape();




private :

    GLint colorLoc;
    GLint positionLoc;
    GLint UVLoc;

};

#endif // TEXTUREDQUAD_H
