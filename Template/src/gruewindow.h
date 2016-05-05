#ifndef GRUEWINDOW_H
#define GRUEWINDOW_H

#include "Shapes/Basis.h"
#include "Shapes/cylinder.h"
#include "Shapes/Cube.h"
#include "GlWindow.h"

class GrueWindow : public GlWindow
{
public:
    GrueWindow();
    ~GrueWindow();

    bool initializeObjects();

    void render();

    void keyPressEvent(QKeyEvent *);

    GLfloat angle1 = 30.0f;
    GLfloat angle2 = 20.0f;

    const GLfloat g_AngleSpeed = 10.0f;

private:
    Basis * basis;

    Cube * cube1;
    Cube * cube2;
    Cube * cube3;
    Cylinder * cyl1;
    Cylinder * cyl2;

    float H1 = 5.0f;
    float H2 = 2.0f;
    float H3 = 7.0f;
    float H4 = 3.0f;
    float L1 = 3.0f;
    float L2 = 10.0f;
    float L3 = 5.0f;
    float P1 = 2.0f;
};

#endif // GRUEWINDOW_H
