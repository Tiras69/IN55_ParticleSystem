#include "cylinder.h"
#include <iostream>


Cylinder::Cylinder(int nbSides, float radius, float heigth)
{
    // Vertices :
    m_TabVertices = new GLfloat[ (nbSides*2 + 2) * 3];

    float angleOffset = (2.0f * 3.14f) / nbSides;
    float currentAngle = 0.0f;

    // Define the two circle
    for(int i = 0 ; i < nbSides ; i++ ){
        m_TabVertices[(i*3)] = sin(currentAngle) * radius;
        m_TabVertices[(i*3)+1] = -(heigth / 2.0f);
        m_TabVertices[(i*3)+2] = cos(currentAngle) * radius;

        m_TabVertices[((i + nbSides)*3)] = sin(currentAngle) * radius;
        m_TabVertices[((i + nbSides)*3)+1] = (heigth / 2.0f);
        m_TabVertices[((i + nbSides)*3)+2] = cos(currentAngle) * radius;

        currentAngle += angleOffset;
    }

    // Ante last point is the center of the first circle.
    m_TabVertices[((nbSides*2 )*3)] = 0.0f;
    m_TabVertices[((nbSides*2 )*3)+1] = -(heigth / 2.0f);
    m_TabVertices[((nbSides*2 )*3)+2] = 0.0f;

    // Last point is the center of the second circle.
    m_TabVertices[((nbSides*2 + 1)*3)] = 0.0f;
    m_TabVertices[((nbSides*2 + 1)*3)+1] = (heigth / 2.0f);
    m_TabVertices[((nbSides*2 + 1)*3)+2] = 0.0f;

    // Circle One :
    m_TabIndicesCircleOne = new GLuint[nbSides + 2];
    nbIndices = nbSides + 2;

    m_TabIndicesCircleOne[0] = nbSides*2;

    for(int i=0 ; i <nbSides; i++)
        m_TabIndicesCircleOne[i+1] = i;

    m_TabIndicesCircleOne[nbSides + 1] = 0;

    // Circle Two :
    m_TabIndicesCircleTwo = new GLuint[nbSides + 2];

    m_TabIndicesCircleTwo[0] = nbSides*2 + 1;

    for(int i=0 ; i <nbSides; i++)
        m_TabIndicesCircleTwo[i+1] = nbSides + i;

    m_TabIndicesCircleTwo[nbSides + 1] = nbSides;

    // Colors :
    m_TabColors = new GLfloat[ (nbSides*2 + 2) * 3];
    for(int i = 0 ; i < (nbSides*2 + 2) ; i++){
        if(i%2 == 0){
            m_TabColors[(i*3)] = 0.0f;
            m_TabColors[(i*3)+1] = 1.0f;
            m_TabColors[(i*3)+2] = 0.0f;
        }else{
            m_TabColors[(i*3)] = 1.0f;
            m_TabColors[(i*3)+1] = 0.0f;
            m_TabColors[(i*3)+2] = 0.0f;
        }
    }

    // Side :
    m_TabIndicesSide = new GLuint[nbSides*2 + 2];
    nbIndicesSide = nbSides*2 + 2;
    for(int i = 0 ; i < nbSides ; i++){
        m_TabIndicesSide[i*2] = i;
        m_TabIndicesSide[i*2 + 1] = nbSides + i;

    }

    m_TabIndicesSide[nbSides*2] = 0;
    m_TabIndicesSide[nbSides*2 + 1] = nbSides;

}

void Cylinder::drawShape(){

    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3 , GL_FLOAT, GL_FALSE, 0, m_TabVertices );

    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, m_TabColors );

    glDrawElements(GL_TRIANGLE_FAN, nbIndices, GL_UNSIGNED_INT, m_TabIndicesCircleOne);

    glDrawElements(GL_TRIANGLE_FAN, nbIndices, GL_UNSIGNED_INT, m_TabIndicesCircleTwo);

    glDrawElements(GL_TRIANGLE_STRIP, nbIndicesSide, GL_UNSIGNED_INT, m_TabIndicesSide);

    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );

}

Cylinder::~Cylinder(){
    delete m_TabVertices;
    delete m_TabColors;

    delete m_TabIndicesCircleOne;
}
