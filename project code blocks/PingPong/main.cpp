
#include<headers.h>
#include<pong.h>






const double fps=45;

WINDOW* w;

      inline void start_screen();
      inline glm::vec2  player_input();
      inline glm::vec2  computer_input( const PADDLE& paddle , const BALL& ball);




int main()
      {INITSOUND;

           WINDOW window("Pong");//creating window
            w=&window;
           window.getcurrentwidthheight(width,height);
           SCREENSIZE(width,height);//creating

           SPRITE background;
           background.loadimg("images/background.png");

           //initializing objects
           PADDLE  paddle1(960,"images/paddle1.png");
           PADDLE  paddle2(20,"images/paddle2.png");
           BALL   ball(12.5, "images/ball.png" );
            glm::vec2 ball_position;

           FONT text(width,height);
           text.loadfont("font/font.ttf",76);



            window.hidecursor();
            //game starts here
            start_screen();


     while(  !window.closed() )
     {

            PLAYER human("YOU");
           PLAYER computer("COMPUTER");
            background.draw(glm::vec2(0,0),glm::vec2(width,height) );
            paddle1.draw();
            paddle2.draw();
            ball.draw();
            text.print("START!!",screencoordinate_x(400),screencoordinate_y(250),1.0,glm::vec3(  0.1,0.1,0.1));
            window.update();
            glfwWaitEvents();

                                                    float spin=0;
                                                    int play=1;
                                                    double last_time= glfwGetTime();
                                                    while( play && human.isalive() && computer.isalive()  )
                                                                {        spin+=0.8;
                                                                        paddle1.move( player_input()                                       );
                                                                        paddle2.move( computer_input(paddle2,ball)  );
                                                                        ball.move(  ball.velocityinfo());

                                                                        paddle1.resolve_collision();
                                                                        paddle2.resolve_collision();
                                                                        ball.resolve_collision(                       );
                                                                        ball.resolve_collision(  paddle1  );
                                                                        ball.resolve_collision(  paddle2  );

                                                                            background.draw(glm::vec2(0,0),glm::vec2(width,height) );
                                                                        paddle1.draw();
                                                                        paddle2.draw();
                                                                        ball.draw(spin*0.1f );
                                                                        human.draw(text,900,20,glm::vec3(0.2,0.3,0.5));
                                                                        computer.draw(text,10,20,glm::vec3(0.5,0.0,0.0));

                                                                        ball_position=ball.positioninfo();
                                                                        if(ball_position.x<=0)
                                                                            {computer.dead();
                                                                            ball.init();
                                                                            }
                                                                        if(ball_position.x>=1000)
                                                                            {human.dead();
                                                                            ball.init();
                                                                            }

                                                                        if(window.iskeypressed( GLFW_KEY_ESCAPE ))
                                                                            play=0;

                                                                        while(glfwGetTime()-last_time<1/fps );
                                                                        last_time=glfwGetTime();
                                                                        window.update();
                                                                }

                if(computer.isalive())
                       text.print("YOU LOST!",screencoordinate_x(400),screencoordinate_y(250),1.0,glm::vec3(  0.1,0.1,0.1));
                else
                       text.print("YOU WON!!",screencoordinate_x(400),screencoordinate_y(250),1.0,glm::vec3(  0.1,0.1,0.1));
                window.closed( window.iskeypressed( GLFW_KEY_ESCAPE ));
                window.update();
                glfwWaitEvents();
     }

         return(0);
      }





             inline void start_screen()
                                   {
                                      FONT text(width,height);
                                       text.loadfont("font/font.ttf",76);

                                            glClearColor(0.0,0.0,0.0,1.0);
                                            w->clear();
                                            text.print("PONG",width/2-100,height/2-100,1,glm::vec3(0.9,0.7,0.2) );
                                            text.print("version 1.0",width-150,height-100,0.3,glm::vec3(0.9,0.7,0.2) );
                                            w->update();
                                            glfwWaitEventsTimeout	(2)	;

                                            w->clear();
                                            text.print("The game you are about to play is PONG!! .  You are free to play and share this game." ,  screencoordinate_x(50)  ,screencoordinate_y(50)  ,0.45,glm::vec3(0.9,0.7,0.2) );
                                            text.print("This game uses the following- " ,  screencoordinate_x(55)  ,screencoordinate_y(90)  ,0.45,glm::vec3(0.9,0.7,0.2) );
                                            text.print("OPENGL   ( Open Graphics Library )  " ,  screencoordinate_x(300)  ,screencoordinate_y(130)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("GLFW        ( openGL FrameWork )" ,  screencoordinate_x(300)  ,screencoordinate_y(170)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("GLEW        ( openGL Extension Wrangler library ) " ,  screencoordinate_x(300)  ,screencoordinate_y(210)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("GLSL          ( openGL Shader Language )  " ,  screencoordinate_x(300)  ,screencoordinate_y(250)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("SOIL           ( Simple Opengl Image Library ) " ,  screencoordinate_x(300)  ,screencoordinate_y(290)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("GLM           ( openGL Mathematics )" ,  screencoordinate_x(300)  ,screencoordinate_y(330)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("FreeType  " ,  screencoordinate_x(300)  ,screencoordinate_y(370)  ,0.6,glm::vec3(0.9,0.7,0.2) );
                                            text.print("created by-  PARTH YADAV  " ,  screencoordinate_x(700)  ,screencoordinate_y(480)  ,0.3,glm::vec3(0.9,0.7,0.2) );
                                             text.print("created on-  29/06/2016  " ,  screencoordinate_x(700)  ,screencoordinate_y(520)  ,0.3,glm::vec3(0.9,0.7,0.2) );
                                            w->update();
                                            glfwWaitEventsTimeout(5);
                                   }



            inline glm::vec2  player_input()
                                    {      if(w->iskeypressed(GLFW_KEY_UP) )
                                                    return glm::vec2(0,-3);

                                            if(w->iskeypressed(GLFW_KEY_DOWN) )
                                                    return  (glm::vec2( 0,3) );

                                           return (glm::vec2( 0,0) );
                                    }



             inline glm::vec2  computer_input( const PADDLE& paddle , const BALL& ball)
                                    {
                                            glm::vec2 paddle_position=paddle.positioninfo();
                                            glm::vec2 ball_position       =ball.positioninfo();
                                            bool visible=( ( paddle_position.x-ball_position.x )*( paddle_position.x-ball_position.x ) +( paddle_position.y-ball_position.y )*( paddle_position.y-ball_position.y )   <  450*450   );

                                        if (visible  )
                                                    {
                                                        float angle=-atan(( paddle_position.y-ball_position.y )/( paddle_position.x-ball_position.x ))*180*7/22;
                                                            if(angle>0)
                                                                            return glm::vec2(0,-1.5);
                                                            if(angle<0)
                                                                            return glm::vec2(0,1.5);
                                                    }
                                        else
                                                    {
                                                        if( 281.25-paddle_position.y>0)
                                                              return( glm::vec2(0,+1.5));
                                                        if( 281.25-paddle_position.y<0)
                                                              return( glm::vec2(0,-1.5));
                                                    }

                                        return glm::vec2(0,0);
                                    }



