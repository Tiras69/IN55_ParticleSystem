#ifndef PARTICLEWINDOW_H
#define PARTICLEWINDOW_H

#include "GlWindow.h"
#include "Particle/texturedquad.h"

class ParticleWindow : public GlWindow
{
public:
    ParticleWindow();
    ~ParticleWindow();

    bool initializeObjects();

    void render();

    void keyPressEvent(QKeyEvent *event);
private:

    TexturedQuad * quad;

};

#endif // PARTICLEWINDOW_H
