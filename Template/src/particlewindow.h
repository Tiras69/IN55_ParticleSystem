#ifndef PARTICLEWINDOW_H
#define PARTICLEWINDOW_H

#include "GlWindow.h"
#include "Particle/texturedquad.h"
#include "Particle/objectpool.h"
#include "Particle/particletransform.h"
#include "Particle/particlesystem.h"
#include "camera.h"

#include<time.h>

class ParticleWindow : public GlWindow
{
public:
    ParticleWindow();
    ~ParticleWindow();

    bool initializeObjects();

    void render();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:

    float frameRate = 1.0f/30.0f;
    float cameraSpeed = 20.0f;
    float mouseSensibility = 0.3f;

    clock_t timeStart;
    clock_t timeEnd;

    Camera * camera;
    TexturedQuad * quad;
    ObjectPool * pool;

    ParticleSystem * particleSystem;

    // Variable Used to check if a direction is pushed
    bool isForwardPressed;
    bool isLeftPressed;
    bool isRightPressed;
    bool isDownPressed;

    Vec2 lastMousePostion;


};

#endif // PARTICLEWINDOW_H
