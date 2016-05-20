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
private:

    float frameRate = 1.0f/30.0f;
    clock_t timeStart;
    clock_t timeEnd;

    Camera * camera;
    TexturedQuad * quad;
    ObjectPool * pool;

    ParticleSystem * particleSystem;
};

#endif // PARTICLEWINDOW_H
