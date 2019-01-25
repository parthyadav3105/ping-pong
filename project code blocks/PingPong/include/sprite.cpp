
#include<sprite.h>

SCREEN  SPRITE::screen;



                bool  SCREEN::INIT(int width,int height)
                {
                    m_width=width;
                    m_height=height;

                    //creates a shader program and loads the sprite shader defined by us for doing 2d  rendering
                    SHADER spriteshader("shaders/sprite.vsh","shaders/sprite.fsh" );

                    //creates the ortho projection matrix according to our screen width and height
                    glm::mat4 projection= glm::ortho( 0.0f ,  static_cast<GLfloat>(m_width) , static_cast<GLfloat>(m_height) , 0.0f ,  -1.0f ,  1.0f );

                    //initilizing our sprite shader for 2d projection
                    spriteshader.SetInteger("image",0,true);
                    spriteshader.SetMatrix4("projection",projection);

                    rendererptr= new SpriteRenderer(spriteshader);
                    if( rendererptr==NULL )
                            {
                                cout<<"ERROR:: screen cannot be initilized "<<endl;
                                return false;
                            }

                    return true;
                }



                SCREEN::~SCREEN()
                {
                    delete[] rendererptr;
                }



    void SPRITE::draw(  glm::vec2 position ,  glm::vec2 size  , GLfloat rotate, glm::vec3 color  )
                {
                    screen.rendererptr-> DrawSprite( texture, position, size , rotate ,color  );
                }

     bool SPRITE::loadimg(const char* path)
                 {
                     int width, height;
                     unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);
                     if( image == NULL )
                     {
                         return false;
                     }
                     texture.Generate ( width ,  height , image);
                     SOIL_free_image_data(  image );
                return true;
                 }

