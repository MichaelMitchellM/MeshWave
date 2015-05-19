
#include "opengl_handler.hpp"

opengl_handler::opengl_handler(){

	glGenVertexArrays(1, &vertex_array_id_);
	glBindVertexArray(vertex_array_id_);

	// generate mesh
	mesh_gen mesh{ 200u, 200u, 0.25f };
	num_verts_ = mesh.num_verts();

	glGenBuffers(1, &vertexbuffer_id_);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_id_);
	glBufferData(GL_ARRAY_BUFFER, mesh.num_bytes(), mesh.mesh(), GL_STATIC_DRAW);

	shader_loader prg_loader{ "wave.vs.glsl", "basic.fs.glsl" };
	program_id_ = prg_loader.program_id();

	mvp_loc_   = glGetUniformLocation(program_id_, "mvp");
	color_loc_ = glGetUniformLocation(program_id_, "in_color");
	theta_loc_  = glGetUniformLocation(program_id_, "theta");

	proj_ = glm::perspective(3.1415926f / 3.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	view_ = cam_.CameraMatrix();
	model_ = glm::mat4(1.0f);

	mvp_ = proj_ * view_ * model_;

	theta_ = 0.0f;
	incr_val_ = 0.01f;

}

opengl_handler::~opengl_handler(){



}

void opengl_handler::Render(){

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	view_ = cam_.CameraMatrix();
	//model_ = glm::translate()
	mvp_ = proj_ * view_ * model_;

	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_id_);
	
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);

	glUseProgram(program_id_);
	glUniformMatrix4fv(mvp_loc_, 1, GL_FALSE, &mvp_[0][0]);
	glUniform1f(theta_loc_, theta_);

	glUniform3f(color_loc_, 1.0f, 0.0f, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, num_verts_);

	glUniform3f(color_loc_, 0.0f, 0.0f, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, num_verts_);

	glDisableVertexAttribArray(0);

	glDisable(GL_DEPTH_TEST);

	theta_ += incr_val_;
	if (abs(theta_) > 3.1415925f){
		//incr_val_ = -incr_val_;
	}
}

