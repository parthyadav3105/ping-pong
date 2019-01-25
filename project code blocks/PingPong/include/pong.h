#ifndef PONG_H_INCLUDED
#define PONG_H_INCLUDED

#include<stdlib.h>
#include<time.h>
#include<sound.h>


int width ,height;
#define MAX_VELOCITY  glm::length(glm::vec2(4.30f,0))

     inline  float  screencoordinate_x(const float& x)
                    {  return(x*width/1000);        }

      inline  float  screencoordinate_y(const float& y)
                    {  return(y*height/562.5);    }

      inline  glm::vec2 screencoordinate( const glm::vec2& pos)
                    {  return ( glm::vec2(  screencoordinate_x(pos.x) ,screencoordinate_y(pos.y)  )     );  }

       inline  float max (const float& x,const float& y)
                    {
                        if(x>y)           return(x);
                        else                 return(y);
                    }
       inline  float min (const float& x,const float& y)
                    {
                        if(x<y)           return(x);
                        else                 return(y);
                    }







class PLAYER
            {      string name;
                    int lives;
            public:
                        PLAYER(string n)                                                      {name=n;  lives=3;}
                        void draw(  FONT& text , int x , int y ,glm::vec3 colour )  const ;
                        void dead()                                                                    {lives--; }
                        bool isalive()  const                                                 { return( lives );}
            };




class OBJECT
            {  protected:
                              glm::vec2 position;
                              glm::vec2 size;
                              glm::vec2 velocity;
                              SPRITE image;
                public:
                              OBJECT()  {;};
                            void move( const glm::vec2& dv )                                                                                                                                   {  position += dv;                                            }
                            glm::vec2 positioninfo( )  const                                                                                                                                          {  return (position ) ;                                      }
                            glm::vec2 sizeinfo( )  const                                                                                                                                                 {  return (size ) ;                                                }
                            glm::vec2 velocityinfo( )  const                                                                                                                                          {  return (velocity ) ;                                       }
                            void draw( const GLfloat& angle=0.0f,const glm::vec3& color=glm::vec3(1.0f)  )                          {  image.draw(screencoordinate(position-size*glm::vec2(0.5,0.5)),screencoordinate(size),angle,color);                     };
            };



class PADDLE:public OBJECT
        {
            public:
                         PADDLE()       { ; };
                         PADDLE(const float& axis , char* path);
                         void move( const glm::vec2& dv  ) ;
                         void resolve_collision( );
        };



class BALL:public OBJECT
        {   float radius;
            public:
                         BALL()       { ; };
                         BALL(   const float& rad ,  char* path);
                         void init();
                         void resolve_collision(const PADDLE& paddle1);
                         void resolve_collision();
        };






        //DEFINATIONS  --------------------------------------------------------









    inline void PLAYER::draw (  FONT& text , int x , int y ,glm::vec3 colour )  const
                    {
                        text.print( name ,screencoordinate_x(x),screencoordinate_y(y),0.5,colour );
                        for(int i=0 ;i<lives ;i++)
                            text.print("*",screencoordinate_x(x+i*30),screencoordinate_y(y+40),1,colour);
                    }




    inline  PADDLE::PADDLE( const float& axis,char* path )
                       {
                           position=glm::vec2(axis,281.25);
                           size=glm::vec2(15, 100);
                           image.loadimg(path);
                           velocity=glm::vec2(0.0,0.0);
                       };

      inline void PADDLE::move(const glm::vec2& dv  )
                       {position+=dv;
                           if ( (dv.y!=0))
                                                   {if   (  ( dv.y>0  )  &&  ( velocity.y <MAX_VELOCITY*15/100  )  )
                                                                   velocity.y+=0.0001;
                                                       if  (  ( dv.y<0  )  &&  ( velocity.y >-MAX_VELOCITY*15/100 )  )
                                                                   velocity.y-=0.0001;
                                                   }
                           if(  dv.y==0 )
                                                       velocity.y=0;
                       }


      inline void PADDLE::resolve_collision( )
                        {  if  (  (position.y-size.y/2<0) || (position.y+size.y/2>556)    )
                                    {   if( position.y-size.y/2<0 )    position.y=0+size.y/2;
                                        if( position.y+size.y/2>556 )    position.y=556-size.y/2;   }
                        }




       inline  BALL::BALL(   const float& rad ,  char* path)
                      {
                          radius=rad;
                          image.loadimg(path);
                          size=glm::vec2(rad*2,rad*2);
                          init();
                       }



        inline void BALL::resolve_collision(const PADDLE& paddle1)
                       {static SOUND snd("hit.wav");

                           float x= max(  paddle1.positioninfo().x - paddle1.sizeinfo().x/2  ,   min(  paddle1.positioninfo().x +paddle1.sizeinfo().x/2, position.x    )   );
                           float y= max(  paddle1.positioninfo().y - paddle1.sizeinfo().y/2  ,   min(  paddle1.positioninfo().y +paddle1.sizeinfo().y/2 , position.y    )   );
                           glm::vec2 nearest(    x     ,   y     );

                                        if (  (nearest.x-position.x)*(nearest.x-position.x) +(nearest.y-position.y)*(nearest.y-position.y)   <   radius*radius)
                                    {     snd.play();
                                                float difference=radius-glm::length(nearest-position);
                                            if(x==paddle1.positioninfo().x - paddle1.sizeinfo().x/2)//left of paddle
                                            {
                                                    position.x-=difference;            velocity.x*=-1;
                                            }
                                            if(x==paddle1.positioninfo().x + paddle1.sizeinfo().x/2)//right of paddle
                                            {
                                                position.x+=difference;            velocity.x*=-1;
                                            }
                                            if(y==paddle1.positioninfo().y - paddle1.sizeinfo().y/2)//up of paddle
                                            {
                                                    position.y-=difference;            velocity.y*=-1;
                                            }
                                            if(y==paddle1.positioninfo().y + paddle1.sizeinfo().y/2)//down of paddle
                                            {
                                                    position.y+=difference;            velocity.y*=-1;
                                            }
                                        velocity+=paddle1.velocityinfo();
                                        velocity=glm::normalize(velocity)*MAX_VELOCITY;

                                    }
                       }



         inline void BALL::resolve_collision()
                       {
                           if( position.y-radius<=0)                                       velocity.y*=-1;
                           if( position.y+radius>=556)                                 velocity.y*=-1;
                       }

          inline void BALL::init()
                       {
                           position=glm::vec2(500,281);
                           double y;
                           time_t t;
                           srand((unsigned)time(&t)  );
                           y=(rand()%100)/50 -0.5;
                           velocity=glm::vec2(1.0,y);
                           velocity=glm::normalize(velocity)*MAX_VELOCITY;
                       }






#endif // PONG_H_INCLUDED
