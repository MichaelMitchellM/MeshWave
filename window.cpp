
#include "window.hpp"

window::window(){

	if (!glfwInit()){
		printf("error - glfw did not init!\n");
		exit(EXIT_SUCCESS);
	}

	// Sampling
	glfwWindowHint(GLFW_SAMPLES, 1);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window_ = glfwCreateWindow(1280, 720, "Wave", NULL, NULL);
	if (window_ == NULL){
		printf("error - glfw window could not be created!\n");
		exit(EXIT_SUCCESS);
	}

	glfwMakeContextCurrent(window_);
	
	glewExperimental = true;
	if (glewInit() != GLEW_OK){
		printf("error - glew could not be init!\n");
		exit(EXIT_SUCCESS);
	}

	gl_handler_ = new opengl_handler;

	glfwSetWindowUserPointer(window_, (void*)gl_handler_);

	glfwSetCursorPosCallback(window_, MouseMove);

	while (!glfwWindowShouldClose(window_)){
		// render
		gl_handler_->Render();

		glfwSwapBuffers(window_);
		glfwPollEvents();
	}


}

window::~window(){

	glfwDestroyWindow(window_);

}

void MouseMove(GLFWwindow* win, double xpos, double ypos){
	opengl_handler* gl_handler = static_cast<opengl_handler*>(glfwGetWindowUserPointer(win));
	gl_handler->cam_.mouse_pos_.x = (float)xpos - 1280.0f / 2.0f;
	gl_handler->cam_.mouse_pos_.y = (float)ypos - 720.0f / 2.0f;
}
