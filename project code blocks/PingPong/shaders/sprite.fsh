
#version 330 core

in vec2 TexCoords;

out vec4 color;

uniform sampler2D   image;
uniform vec3      spriteColor;

void main()
            {
                vec4 Texcolor=vec4(spriteColor, 1.0) * texture(image, TexCoords);
                if(Texcolor.a < 0.1)
                          discard;
                 color = Texcolor;
            }
