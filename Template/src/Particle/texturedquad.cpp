#include "texturedquad.h"

TexturedQuad::TexturedQuad(std::string texName)
{
    /* Vertices Stuff */
    GLfloat tmptabVertices[] = {1.0f, 1.0f, 0.0f,  -1.0f, 1.0f, 0.0f,  -1.0f, -1.0f, 0.0f,
                               1.0f, 1.0f, 0.0f,  -1.0f, -1.0f, 0.0f,  1.0f, -1.0f, 0.0f,};

    GLuint tmptabIndices[] = {0, 1, 2,  3, 4, 5};

    /* Color Stuff */
    GLfloat tmptabColor[] = {1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f};

    /* UV Stuff */
    GLfloat tmpUVCoordinates[] = {1.0f, 0.0f,    0.0f, 0.0f,0.0f, 1.0f,
                                 1.0f, 0.0f,0.0f, 1.0f, 1.0f, 1.0f};

    /* Copy stuff */
    for(int i = 0 ; i < 6*3 ; i++){
        tabVertices[i] = tmptabVertices[i];
        tabColor[i] = tmptabColor[i];
    }

    for(int i = 0 ; i < 2*3 ; i++)
        tabIndices[i] = tmptabIndices[i];

    for(int i = 0 ; i < 6*2 ; i++)
        UVCoordinates[i] = tmpUVCoordinates[i];

    opacity = 0.3f;

    /* Gen Texture */
    glGenTextures(1, &texID);
    std::cout << glGetError() << std::endl;
    glBindTexture(GL_TEXTURE_2D, texID);
    std::cout << glGetError() << std::endl;
    image = SOIL_load_image(texName.c_str(),
                            &imageWidth,
                            &imageHeight,
                            0,
                            SOIL_LOAD_RGBA);
    std::cout << glGetError() << std::endl;
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 imageWidth,
                 imageHeight,
                 0,
                 GL_BGRA,
                 GL_UNSIGNED_BYTE,
                 image);
    std::cout << glGetError() << std::endl;


}

void TexturedQuad::drawShape(){
    //initGLFrame();
                glDrawElements(GL_TRIANGLES, 2*3, GL_UNSIGNED_INT, tabIndices);
    //closeGLFrame();
}

void
TexturedQuad::initGLFrame(){
    /* ALPHA STUFF */
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLint opacityLoc = glGetUniformLocation(m_Framework->getCurrentShaderId(), "opacity");
    glUniform1f(opacityLoc, opacity);

    UVLoc = glGetAttribLocation(m_Framework->getCurrentShaderId(), "texcoord");
    glVertexAttribPointer(UVLoc, 2, GL_FLOAT, GL_FALSE, 0, UVCoordinates);
    glEnableVertexAttribArray(UVLoc);

        /* VERTEX COLOR STUFF */
        positionLoc = glGetAttribLocation(m_Framework->getCurrentShaderId(), "position");
        colorLoc = glGetAttribLocation(m_Framework->getCurrentShaderId(), "color");

        glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, 0, tabVertices);
        glEnableVertexAttribArray(positionLoc);

            glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, tabColor);
            glEnableVertexAttribArray(colorLoc);

            glBindTexture(GL_TEXTURE_2D, texID);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexImage2D(GL_TEXTURE_2D,
                             0,
                             GL_RGBA,
                             imageWidth,
                             imageHeight,
                             0,
                             GL_RGBA,
                             GL_UNSIGNED_BYTE,
                             image);
}

void
TexturedQuad::closeGLFrame(){
    glBindTexture(GL_TEXTURE_2D, 0);

    glDisableVertexAttribArray(colorLoc);

glDisableVertexAttribArray(positionLoc);

glDisableVertexAttribArray(UVLoc);

}
