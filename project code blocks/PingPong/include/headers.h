#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED


// GLEW
#define GLEW_STATIC
#include <glew.h>


// GLFW
#include <glfw3.h>

//simple opengl  image loading library
#include <soil/SOIL.h>

//opengl mqth library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Our includes

//for creating window
#include<windows.h>
#include<windows.cpp>

//texture creating library
#include<texture.h>
#include<texture.cpp>

//texture drawing library
#include<spriterender.h>
#include<spriterender.cpp>

//shader program creating library
#include<shader.h>
#include<shader.cpp>

//sprite and screen drawing library
#include<sprite.h>
#include<sprite.cpp>

//text rendering library
#include<text.h>
#include<text.cpp>

//sound
#include<sound.h>



#endif // HEADERS_H_INCLUDED
