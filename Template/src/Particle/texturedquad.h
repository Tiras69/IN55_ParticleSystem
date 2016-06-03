#ifndef TEXTUREDQUAD_H
#define TEXTUREDQUAD_H

#include "SOIL.h"
#include "./Object3D.h"
#include "renderer.h"

#include <string>
#include <stdio.h>
#include <QDir>
#include <iostream>

class TexturedQuad : public Renderer, public Object3D
{
public:
    TexturedQuad(std::string texName);

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
