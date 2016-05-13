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
protected:
    void drawShape();



private :


};

#endif // TEXTUREDQUAD_H
