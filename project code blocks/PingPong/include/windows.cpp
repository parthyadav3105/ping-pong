
#define GLEW_STATIC
#include<glew.h>

#include<windows.h>



#include<iostream>




           void resize_callback( GLFWwindow* window, int w, int h )                                                                 {         glViewport(0,0,w,h) ;       }
           void key_callback( GLFWwindow* window, int key,int scancode, int action,int mode);
           void mouse_callback( GLFWwindow* window, int key,int action,int mode);
           void cursor_callback( GLFWwindow* window, double xpos,double ypos);
           void error_callback(int id, const char* description)                                                                                     {std::cout << description << std::endl;}


       inline  bool WINDOW::initglfw()
                                         {

                                               // Init GLFW
                                                 if  ( ! glfwInit() )
                                                           {
                                                                 std::cout<<"glfw was not initilized"<<std::endl;
                                                                 return (false);
                                                          }

                                                          glfwSetErrorCallback(&error_callback);
                                                    // Set all the required options for GLFW
                                                 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
                                                  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                                                  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
                                                    glfwWindowHint( GLFW_REFRESH_RATE, 60 );

                                                 return(  true);
                                         }

         inline  bool WINDOW::init()
                                       {
                                                     //window initilization
                                                  // Create a GLFWwindow object that we can use for GLFW's functions
                                             m_windows=glfwCreateWindow( m_width ,m_height, m_title ,NULL ,NULL );
                                             if( m_windows== NULL )
                                                      {
                                                            std::cout<<"failed to create window"<<std::endl;
                                                            return(false);
                                                      }

                                               glfwMakeContextCurrent(m_windows);

                                                glfwSetWindowUserPointer(m_windows,this),
                                                glfwSetWindowSizeCallback(m_windows, resize_callback );
                                                 glfwSetKeyCallback(m_windows, key_callback );
                                                 glfwSetMouseButtonCallback(m_windows, mouse_callback );
                                                 glfwSetCursorPosCallback(m_windows,cursor_callback);





                                                glewExperimental = GL_TRUE;
                                               if( glewInit()  != GLEW_OK)
                                               {
                                                   std::cout<<"failed to initilize glew "<<std::endl;
                                                   return(false);
                                               }

                                               std::cout<<"opengl version  "<<glGetString(GL_VERSION)<<std::endl;

                                               glEnable(GL_BLEND);
                                               glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



                                                return( true);
                                    }




                             //creates  a default window

              WINDOW::WINDOW(  )
                                    {
                                        m_title = "WINDOW";
                                        m_height = 600;
                                        m_width= 900;

                                         if (  !initglfw()  )
                                                { glfwTerminate();
                                                    std::cout<<"failed to initialize glfw"<<std::endl ;
                                                }
                                          if (  !init()  )
                                                { glfwTerminate();
                                                    std::cout<<"failed to create window "<<std::endl ;
                                                }

                                         for ( int  i = 0  ; i < MAX_KEYS ; i++)
                                                      m_keys[i]=false;

                                        for ( int j= 0  ; j < MAX_BUTTONS ; j++)
                                                      m_buttons[j]=false;



                                     }


                             //creates a window according to specification
      WINDOW::WINDOW(int width ,int height ,char* title)
                                    {
                                        m_title = title;
                                        m_height = height;
                                        m_width= width;

                                         if (  !initglfw()  )
                                                { glfwTerminate();
                                                    std::cout<<"failed to initialize glfw"<<std::endl ;
                                                }

                                         if (  !init()  )
                                                 std::cout<<"failed to create window " ;

                                            for ( int  i = 0  ; i < MAX_KEYS ; i++)
                                                      m_keys[i]=false;

                                        for ( int j= 0  ; j < MAX_BUTTONS ; j++)
                                                      m_buttons[j]=false;

                                    }



                        //creates a fullscreen window
      WINDOW::WINDOW(char* title)
                                    {
                                        m_title = title;

                                         if (  !initglfw()  )
                                                { glfwTerminate();
                                                    std::cout<<"failed to initialize glfw"<<std::endl ;
                                                }

                                                 const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
                                                  m_width = mode->width;
                                                  m_height = mode->height;
                                                  glfwWindowHint(GLFW_RED_BITS,mode->redBits);
                                                  glfwWindowHint(GLFW_GREEN_BITS,mode->greenBits);
                                                  glfwWindowHint(GLFW_BLUE_BITS,mode->blueBits);
                                                  glfwWindowHint(GLFW_REFRESH_RATE,mode->refreshRate);

                                                     //window initilization
                                             m_windows=glfwCreateWindow( m_width ,m_height, m_title ,glfwGetPrimaryMonitor() ,NULL );
                                             if( m_windows== NULL )
                                                            std::cout<<"failed to create window"<<std::endl;

                                               glfwMakeContextCurrent(m_windows);

                                                glfwSetWindowUserPointer(m_windows,this),
                                                glfwSetWindowSizeCallback(m_windows, resize_callback );
                                                 glfwSetKeyCallback(m_windows, key_callback );
                                                 glfwSetMouseButtonCallback(m_windows, mouse_callback );
                                                 glfwSetCursorPosCallback(m_windows,cursor_callback);

                                                glewExperimental = GL_TRUE;
                                               if( glewInit()  != GLEW_OK)
                                                     std::cout<<"failed to initilize glew "<<std::endl;


                                               std::cout<<"opengl version  "<<glGetString(GL_VERSION)<<std::endl;

                                               glEnable(GL_BLEND);
                                               glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


                                            for ( int  i = 0  ; i < MAX_KEYS ; i++)
                                                      m_keys[i]=false;

                                        for ( int j= 0  ; j < MAX_BUTTONS ; j++)
                                                      m_buttons[j]=false;

                                    }






                              //do some termination work
     WINDOW::~WINDOW()
                                    {
                                          // Terminate GLFW, clearing any resources allocated by GLFW.
                                        glfwTerminate();
                                    }

    void WINDOW::hidecursor()
                                    {glfwSetInputMode(m_windows,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);
                                    }

    void WINDOW::clear()
                                   {
                                       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
                                    }

     void WINDOW::update()
                                  {
                                      glfwSwapBuffers(m_windows);
                                      glfwPollEvents();

                                  }

    bool WINDOW::closed()  const
                              {
                                  return(glfwWindowShouldClose( m_windows ));
                              }

     void WINDOW::closed(bool setit)  const
                              {
                                  glfwSetWindowShouldClose( m_windows ,setit);
                              }




                           void key_callback( GLFWwindow* window, int key,int scancode, int action,int mode)
                                    {
                                           WINDOW* win=   (WINDOW*)( glfwGetWindowUserPointer(window));

                                           win->m_keys[ key ]= ( action != GLFW_RELEASE  );

                                     }

                              void mouse_callback( GLFWwindow* window, int button,int action,int mode)
                              {
                                   WINDOW* win=   (WINDOW*)( glfwGetWindowUserPointer(window));

                                         win->m_buttons[ button ]= ( action != GLFW_RELEASE  );

                              }

                              void cursor_callback( GLFWwindow* window, double xpos,double ypos)
                              {
                                    WINDOW* win=   (WINDOW*)( glfwGetWindowUserPointer(window));

                                    win->ms_x=(int)(xpos);
                                    win->ms_y=(int)(ypos);

                              }



                         bool WINDOW::iskeypressed(unsigned int keycode)  const
                                   {
                                       if( keycode >= MAX_KEYS )
                                             return( false );
                                       return(m_keys[keycode]);
                                   }

                        bool WINDOW::isbuttonpressed(unsigned int button)  const
                                {
                                       if( button >= MAX_BUTTONS )
                                             return( false );
                                       return( m_buttons[button] );
                                   }

                   void WINDOW::getmouseposition(double& x,double& y)  const
                              {
                                  x=ms_x;
                                  y=ms_y;
                               }


