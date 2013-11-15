WeirdTetris
===========

Tetris with noncontiguous tetrominos


Compile & run
=============

1. 	(Unix) Install build-essential & others
	
		apt-get install build-essential g++

2. 	(Windows) Install Visual Studio Express

		http://www.visualstudio.com/downloads

2. 	(Unix) Install needed libraries:
	
		apt-get install libglm-dev libglew-dev libglu1-mesa-dev libxxf86vm-dev libx11-dev libxi-dev libxrandr-dev libfreeimage-dev

	or similar, depending on system.

2. 	(Windows) Install needed libraries:

		http://glew.sourceforge.net/index.html
		http://freeimage.sourceforge.net/download.html

3. 	Install glfw

		http://www.glfw.org/download.html
	
4.	(Unix) Run make from top directory
	
		cd /path/to/WeirdTetris/
		make

4. 	(Windows) Setup Visual Studio solution

		Create new empty project
		Right click project > Properties > Configuration Properties > Linker > Input > Additional Dependencies = "kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies);glfw3.lib;opengl32.lib;glew32.lib;glu32.lib;FreeImage.lib"
		Add NuGet package for GLM
		Compile
		Copy res directory into resulting Binary directory (Debug/Release)
	
5.	Run weird tetris
	
		./weirdtetris
	
	Left/Right to move, Up/Z to rotate, Shift to hold, Space to drop, Escape to close.
