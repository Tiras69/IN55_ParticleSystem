#ifndef PARTICLEWINDOW_H
#define PARTICLEWINDOW_H

#include "GlWindow.h"
#include "Particle/texturedquad.h"
#include "Particle/objectpool.h"
//#include "Particle/particletransform.h"
#include "Particle/particlesystem.h"
//#include "Particle/sphereemitter.h"
#include "Particle/coneemitter.h"
#include "camera.h"

#include<time.h>
#include <fstream>
#include <Json/json/json.h>
#include <string>
#include <unistd.h>

class ParticleWindow : public GlWindow
{
public:
    ParticleWindow();
    ~ParticleWindow();


    ShapeEmitter * importJSON();

    bool initializeObjects();

    void render();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:

    int numPart;
    int rate;
    std::string texName;

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
