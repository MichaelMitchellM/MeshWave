
#pragma once

// so windows can use fopen
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <fstream>
#include <string>

#define GLEW_STATIC
#include <gl/glew.h>

class shader_loader{

private:
	GLuint program_id_;

public:
	shader_loader(const char* vs_file_name, const char* fs_file_name);
	~shader_loader();
	GLuint program_id(){ return program_id_; }

};
