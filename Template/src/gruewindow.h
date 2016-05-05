#ifndef GRUEWINDOW_H
#define GRUEWINDOW_H

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
};

#endif // GRUEWINDOW_H
