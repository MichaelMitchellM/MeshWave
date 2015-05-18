
#pragma once

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtc/quaternion.hpp>


class camera{

private:
	glm::vec3 pos_;
	glm::vec3 up_;
	glm::quat ori_;

public:
	glm::vec2 mouse_pos_;

public:
	camera();
	camera(glm::vec3 pos);
	~camera();

	void pos(glm::vec3 pos){ pos_ = pos; }
	glm::vec3 pos(){ return pos_; }

	glm::mat4 CameraMatrix();

};
