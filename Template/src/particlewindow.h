#ifndef PARTICLEWINDOW_H
#define PARTICLEWINDOW_H

#include "GlWindow.h"
#include "Particle/texturedquad.h"
#include "Particle/objectpool.h"
#include "Particle/particletransform.h"

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

    clock_t timeStart;
    clock_t timeEnd;


    TexturedQuad * quad;
    ObjectPool * pool;

};

#endif // PARTICLEWINDOW_H
