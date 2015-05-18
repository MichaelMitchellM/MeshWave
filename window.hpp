

#pragma once

#include <cstdio>
#include <cstdlib>

#define GLEW_STATIC
#include <gl/glew.h>
#include <gl/glfw3.h>

#include "opengl_handler.hpp"

class window{

private:
	GLFWwindow* window_;

	opengl_handler* gl_handler_;

public:

	window();
	~window();

};

void MouseMove(GLFWwindow* win, double xpos, double ypos);
