# PING-PONG
	This is a a simple remake of traditional ping-pong game.One paddle is controlled by us as human and the other paddle is controlled by program.

	The code is open source. The game is designed to be cross platform.

### Controls
		**UP arrow key** to move paddle up
		**DOWN arrow key** to move paddle down

### Binary file
	Binary executable for windows is stored in **bin** folder.
	The executable has been tested in windows 7,windows 10.

### Compiling source code
	The source code for wrote and tested in windows 7 in codeblocks ide using the default g++ compiler.
	You may not face any problem in compiling if you use the codeblock project file stored in "project code block" folder.
	
	If you are compiling on some other ide or directly in terminal then you would have to link the following static libraries stored in lib folder.
	"glew32s.lib"	"libglfw3dll.a"		"libglfw3.a"	"libSOIL.a"		"freetype.lib"	"libopengl32.a"
	and give following linker options
	"-lmingw32" "-lSDL2main" "-lSDL2" "-lSDL2_mixer"
	
	If you are compiling on linux or mac then you will have to get libraries for that platform first.

	DLLs involved
	glfw3.dll freetype6.dll SDL2.dll SDL2_mixer.dll zlib1.dll

### Libs and frameworks used
	opengl glfw soil freetype SDL(for audio only) glm 

audio file "hit.wav" and font "font.ttf" are not made by me.

CREDITS:
	https://learnopengl.com/

### Extra info
	The game runs in full-screen mode and uses primary monitor.
	The computer paddle is able get ball position only when ball at left half of the screen.

	Problem with gameplay-
	the ball and paddle moves with different speed on diiferent system with different performance because dt=currentTime-lastTime was not multiplied with their velocity in game loop.
