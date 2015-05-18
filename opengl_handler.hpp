
#pragma once

#define GLEW_STATIC // to static link to glew
#include <GL/glew.h>

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>

#include "camera.hpp"
#include "mesh_gen.hpp"
#include "shader_loader.hpp"

class opengl_handler{

private:
	GLuint vertex_array_id_;

	unsigned num_verts_;
	GLuint vertexbuffer_id_;

	GLuint program_id_;

	GLuint mvp_loc_;
	GLuint color_loc_;
	GLuint theta_loc_;

	glm::mat4 proj_;
	glm::mat4 view_;
	glm::mat4 model_;
	glm::mat4 mvp_;

	float theta_;
	float incr_val_;

public:
	camera cam_;

public:
	opengl_handler();
	~opengl_handler();

	void Render();

};
