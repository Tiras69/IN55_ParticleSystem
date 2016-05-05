#ifndef TP01_h
#define TP01_h

#include "Shapes/Basis.h"
#include "Shapes/cylinder.h"
#include "Shapes/Cube.h"
#include "GlWindow.h"


class TP01 : public GlWindow
{
	public:
		TP01();
        ~TP01();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();

		/*!
		*\brief Rendu de la scène.
		*/
		void render();

		void keyPressEvent(QKeyEvent *);

        GLfloat angle1 = 30.0f;
        GLfloat angle2 = 20.0f;

        const GLfloat g_AngleSpeed = 10.0f;

    private:
        double deltaTime;
        clock_t end;
        clock_t start;

        Basis* g_Basis;
        Cube * Tete;
        Cube * Torse;
        Cube * BrasDroit;
        Cube * BrasGauche;
        Cube * JambeDroite;
        Cube * JambeGauche;

        float degrePerSecond = 180.0f;
        float currentAngle = 0.0f;
        bool negatif = false;
};


#endif
