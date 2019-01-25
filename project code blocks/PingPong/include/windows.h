#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED


#define GLEW_STATIC
#include<glew.h>
#include<glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS  32


class WINDOW
             {   public:
                      GLFWwindow * m_windows;
                 private:
                      
                      char* m_title;
                      int m_width;
                      int m_height;

                      bool  m_keys[ MAX_KEYS ];
                      bool  m_buttons[MAX_BUTTONS];
                      int ms_x,ms_y;

                            inline  bool init() ;
                            inline  bool initglfw() ;


                 public:



                             //creates  a default window
                             WINDOW();

                            //creates a window according to specification
                             WINDOW(int width ,int height ,char* title);

                             //creates a fullscreen window
                             WINDOW(char* title);

                              //do some termination work
                              ~WINDOW();
                              
                              void hidecursor();

                              void getcurrentwidthheight(int &w,int& h)    {  w=m_width;  h=m_height;        }

                              //clears the screen
                              void clear();

                              //set some callback function
                             void update();

                             //checks weather window is closed or not
                             bool  closed()  const;
                             void closed(bool)  const;

                            friend void key_callback( GLFWwindow* window, int key,int scancode, int action,int mode);
                            friend void mouse_callback( GLFWwindow* window, int key,int action,int mode);
                            friend void cursor_callback( GLFWwindow* window, double xpos,double ypos);


                            bool iskeypressed(unsigned int keycode)   const;
                            bool isbuttonpressed(unsigned int button)   const;
                            void getmouseposition(double& x,double& y)   const;

             };












#endif // WINDOWS_H_INCLUDED
