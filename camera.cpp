
#include "camera.hpp"

camera::camera()
	:
	pos_{ 0.0f, 0.0f, -10.0f },
	up_{ 0.0f, 0.0f, 1.0f }
{
	ori_ = glm::normalize(glm::angleAxis(-3.1415926f / 2.0f, glm::vec3{ 1.0f, 0.0f, 0.0f }));
	ori_ = glm::normalize(glm::angleAxis(3.1415926f, glm::vec3{ 0.0f, 0.0f, 1.0f }) * ori_);
}

camera::camera(glm::vec3 pos)
	:
	pos_{ pos },
	up_ { 0.0f, 0.0f, 1.0f }
{
	ori_ = glm::normalize(glm::angleAxis(-3.1415926f / 2.0f, glm::vec3{ 1.0f, 0.0f, 0.0f }));
	ori_ = glm::normalize(glm::angleAxis(3.1415926f, glm::vec3{ 0.0f, 0.0f, 1.0f }) * ori_);
}

camera::~camera(){

}

glm::mat4 camera::CameraMatrix(){

	// left right
	ori_ = glm::normalize(glm::angleAxis(mouse_pos_.x / 50000.0f, glm::vec3{ 0.0f, 0.0f, 1.0f })) * ori_;

	// up down
	glm::vec3 left{ 1.0f, 0.0f, 0.0f };
	left = ori_ * left;
	glm::normalize(left);
	ori_ = glm::normalize(glm::angleAxis(mouse_pos_.y / -100000.0f, left)) * ori_;

	glm::mat4 view_mat = glm::mat4_cast(glm::conjugate(ori_));
	view_mat = glm::translate(view_mat, -pos_);
	return view_mat;
}
