#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED


enum SHAPE { RECTANGLE=0,CIRCLE };

struct SOLID
              {
                  SHAPE shape;
                  float values[ 4 ];                                                                      //values[  i ]    where i=
              };                                                                                                         /*  for rectangle            i = 0 = x                   ;       i = 1 = y                     ;               i = 2 = width          ;            i = 3  = height
                                                                                                                               for  circle                      i = 0 = x                    ;       i = 1 = y                     ;               i = 2 = radius
                                                                                                                        */

class CHECK
            {
                static bool COLLISION(const SOLID& a ,const SOLID& b) ;
                static bool COLLISION_CIRCLE_CIRCLE( const SOLID &a ,const SOLID& b) ;
                static bool COLLISION_RECTANGLE_RECTANGLE(const SOLID& a ,const SOLID& b) ;
                static bool COLLISION_RECTANGLE_CIRCLE(const SOLID& a ,const SOLID& b) ;
            };

            bool CHECK::COLLISION_CIRCLE_CIRCLE( const SOLID &a ,const SOLID& b)
                        {return(  (a.values[0]-b.values[0])*(a.values[0]-b.values[0]) + (a.values[1]-b.values[1])*(a.values[1]-b.values[1])  <   (a.values[2]+b.values[2] )*(a.values[2]+b.values[2] )  );}

             bool CHECK::COLLISION_RECTANGLE_RECTANGLE( const SOLID &a ,const SOLID& b)
                        {return   (  ! (     (a.values[2]<b.values[0] )   ||   (a.values[0]>b.values[2] )   ||   (a.values[1]>b.values[3] )    ||(a.values[3]<b.values[1] )    )       ) ;}

              bool CHECK::COLLISION_RECTANGLE_CIRCLE( const SOLID &a ,const SOLID& b)
                         {
                             float nearest_x=max(  a.values[0]  ,  min( a.values[2] , b.values[0] )    );
                             float nearest_y=max(  a.values[1]  ,  min( a.values[3] , b.values[1] )    );
                             return(  ( nearest_x-b.values[0])* ( nearest_x-b.values[0])+ (nearest_y-b.values[1])*(nearest_y-b.values[1])  <   b.values[2] *b.values[2]    );
                         }

             bool CHECK::COLLISION( const SOLID &a ,const SOLID& b)
                         {
                             if ( a.shape==RECTANGLE  )
                                                        {
                                                             if( b.shape==RECTANGLE )             return COLLISION_RECTANGLE_RECTANGLE( a,b );
                                                             if(  b.shape==CIRCLE)                          return COLLISION_RECTANGLE_CIRCLE( a,b );
                                                        }
                              if ( a.shape==CIRCLE  )
                                                       {
                                                             if( b.shape==RECTANGLE )              return COLLISION_RECTANGLE_CIRCLE( b,a );
                                                             if(  b.shape==CIRCLE)                           return  COLLISION_CIRCLE_CIRCLE( a,b );
                                                        }
                             cout<<"PROBLEM IN <collision.h>  in function COLLISION( SOLID a,SOLID b )";
                             return 0;
                         }




#endif // COLLISION_H_INCLUDED
