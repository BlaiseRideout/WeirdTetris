WeirdTetris
===========

Tetris with noncontiguous tetrominos


Compile & run
=============

1. 	Install build-essential & others
	
		apt-get install build-essential g++

2. 	(Unix) Install needed libraries:
	
		apt-get install libglm-dev libglew-dev libglu1-mesa-dev libxxf86vm-dev libx11-dev libxi-dev libxrandr-dev libfreeimage-dev

	or similar, depending on system.

2. 	(Windows) Install needed libraries:

		http://glew.sourceforge.net/index.html
		http://freeimage.sourceforge.net/download.html

3. 	Install glfw

		http://www.glfw.org/download.html
	
4.	Run make from top directory
	
		cd /path/to/WeirdTetris/
		make
	
5.	Run weird tetris
	
		./weirdtetris
	
	Left/Right to move, Up/Z to rotate, Shift to hold, Space to drop, Escape to close.
