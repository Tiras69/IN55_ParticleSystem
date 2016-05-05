#ifndef TESTCAMERA_H
#define TESTCAMERA_H

#include "GlWindow.h"
#include "camera.h"
#include "Shapes/Cube.h"

#include <iostream>

class TestCamera : public GlWindow
{
public:
    TestCamera();
    ~TestCamera();

    bool initializeObjects();

    void render();

    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

private:

    Camera * cam1;
    Cube * incredibleCubeTest;

    GLfloat angle1 = 30.0f;
    GLfloat angle2 = 20.0f;

    const GLfloat g_AngleSpeed = 10.0f;
};

#endif // TESTCAMERA_H
