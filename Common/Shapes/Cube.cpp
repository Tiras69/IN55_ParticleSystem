#include"Shapes/Cube.h"

Cube::Cube(GLfloat x, GLfloat y, GLfloat z){

    GLfloat trueX = x / 2.0f;
    GLfloat trueY = y / 2.0f;
    GLfloat trueZ = z / 2.0f;

    GLfloat tmptab[] = {-trueX,-trueY,-trueZ, trueX,-trueY,-trueZ, trueX,trueY,-trueZ, -trueX,trueY,-trueZ,
                        -trueX,-trueY,trueZ, trueX,-trueY,trueZ, trueX,trueY,trueZ, -trueX,trueY,trueZ};

    GLuint tmptabI[] = {0,1,3, 3,1,2,
                         1,5,2, 2,5,6,
                         3,2,7, 7,2,6,
                         5,4,6, 6,4,7,
                         4,5,0, 0,5,1,
                         4,0,7, 7,0,3};

    for(int i= 0 ; i< 8*3 ; i++)
        m_TabVertices[i] = tmptab[i];

    for(int i = 0 ; i < 8 ; i++){
        if(i%2 == 0){
            m_TabColors[i*3] = 0.0f;
            m_TabColors[i*3 + 1] = 1.0f;
            m_TabColors[i*3 + 2] = 0.0f;
        }else{
            m_TabColors[i*3] = 0.0f;
            m_TabColors[i*3 + 1] = 0.0f;
            m_TabColors[i*3 + 2] = 1.0f;
        }
    }

    for(int i = 0 ; i< 6*2*3 ; i++)
        m_TabIndices[i] = tmptabI[i];

}

Cube::Cube(GLfloat length){
    GLfloat val = length / 2.0f;

    GLfloat tmptab[] = {-val,-val,-val, val,-val,-val, val,val,-val, -val,val,-val,
                       -val,-val,val, val,-val,val, val,val,val, -val,val,val};
    GLuint tmptabI[] = {0,1,3, 3,1,2,
                         1,5,2, 2,5,6,
                         3,2,7, 7,2,6,
                         5,4,6, 6,4,7,
                         4,5,0, 0,5,1,
                         4,0,7, 7,0,3};

    for(int i= 0 ; i< 8*3 ; i++)
        m_TabVertices[i] = tmptab[i];

    for(int i = 0 ; i < 8 ; i++){
        if(i%2 == 0){
            m_TabColors[i*3] = 0.0f;
            m_TabColors[i*3 + 1] = 1.0f;
            m_TabColors[i*3 + 2] = 0.0f;
        }else{
            m_TabColors[i*3] = 0.0f;
            m_TabColors[i*3 + 1] = 0.0f;
            m_TabColors[i*3 + 2] = 1.0f;
        }
    }

    for(int i = 0 ; i< 6*2*3 ; i++)
        m_TabIndices[i] = tmptabI[i];

}

Cube::~Cube(){
}

void Cube::drawShape(){

    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
        glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, m_TabVertices );
        GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
        glEnableVertexAttribArray( var2 );
            glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, m_TabColors );

            glDrawElements(GL_TRIANGLES, 6*3*2, GL_UNSIGNED_INT, m_TabIndices);
        glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
}
