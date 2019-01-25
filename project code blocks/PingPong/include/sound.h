
#ifndef _SOUND_H
#define _SOUND_H

#include<SDL_mixer.h>

#define INITSOUND Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

class SOUND
{Mix_Chunk* snd;
 public:
    SOUND(char* file)   {snd=Mix_LoadWAV(file);}
    ~SOUND( )                    {  Mix_FreeChunk(snd);}
   void play()                                 {Mix_PlayChannel(-1,snd,0);}
};

class BACKGROUNDMUSIC
{Mix_Music* msc;
 public:
    BACKGROUNDMUSIC(char* file)   {msc=Mix_LoadMUS(file);}
    ~BACKGROUNDMUSIC( )                    {  Mix_FreeMusic(msc);}
   void play()                                 {Mix_PlayMusic(msc,-1);}
};


#endif /* _SDL_MIXER_H */
