#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

// GLEW
#define GLEW_STATIC
#include <glew.h>

//opengl mqth library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//simple opengl  image loading library
#include <soil/SOIL.h>

//texture creating library
#include<texture.h>

//texture drawing library
#include<spriterender.h>

//shader program creating library
#include<shader.h>

#define   SCREENSIZE(x,y)   SPRITE::screen.INIT(x,y)


class SCREEN
           {
               public:
                         SpriteRenderer* rendererptr;

               private:
                          int m_width;
                          int m_height;

               public:
                               SCREEN()  {  ;}
                               bool INIT(int width,int height);
                               ~SCREEN();
           };


class SPRITE
          {
              public:
                            static SCREEN screen;
          private:
                           Texture2D texture;
          public:
                           bool loadimg(const char* path);
                          void draw( glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f)  );

          };













#endif // SPRITE_H_INCLUDED
