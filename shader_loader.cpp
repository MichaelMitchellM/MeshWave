
#include "shader_loader.hpp"

shader_loader::shader_loader(const char* vs_file_name, const char* fs_file_name){

	FILE* vs_file = fopen(vs_file_name, "r");
	FILE* fs_file = fopen(fs_file_name, "r");

	GLuint vs_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs_id = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vs_code;
	std::string fs_code;

	std::ifstream vs_stream{ vs_file };
	std::ifstream fs_stream{ fs_file };

	if (vs_stream.is_open()){
		std::string line = "";
		while (std::getline(vs_stream, line)){
			vs_code += "\n" + line;
		}
		vs_stream.close();
		fclose(vs_file);
	}
	else{
		printf("error - unable to open fstream to vs_file : %s\n", vs_file_name);
		exit(EXIT_SUCCESS);
	}

	if (fs_stream.is_open()){
		std::string line = "";
		while (std::getline(fs_stream, line)){
			fs_code += "\n" + line;
		}
		fs_stream.close();
		fclose(fs_file);
	}
	else{
		printf("error - unable to open fstream to fs_file : %s\n", fs_file_name);
		exit(EXIT_SUCCESS);
	}

	GLint result = GL_FALSE;

	int info_log_len;

	printf("compiling vertex shader : %s\n", vs_file_name);
	const char* vs_ptr = vs_code.c_str();
	glShaderSource(vs_id, 1, &vs_ptr, NULL);
	glCompileShader(vs_id);
	glGetShaderiv(vs_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vs_id, GL_INFO_LOG_LENGTH, &info_log_len);
	char* vs_err = new char[info_log_len];
	glGetShaderInfoLog(vs_id, info_log_len, NULL, vs_err);
	printf("%s\n", vs_err);

	printf("compiling fragment shader : %s\n", fs_file_name);
	const char* fs_ptr = fs_code.c_str();
	glShaderSource(fs_id, 1, &fs_ptr, NULL);
	glCompileShader(fs_id);
	glGetShaderiv(fs_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fs_id, GL_INFO_LOG_LENGTH, &info_log_len);
	char* fs_err = new char[info_log_len];
	glGetShaderInfoLog(fs_id, info_log_len, NULL, fs_err);
	printf("%s\n", fs_err);

	printf("linking program\n");
	program_id_ = glCreateProgram();
	glAttachShader(program_id_, vs_id);
	glAttachShader(program_id_, fs_id);
	glLinkProgram(program_id_);
	glGetProgramiv(program_id_, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &info_log_len);
	char* prg_err = new char[info_log_len];
	glGetProgramInfoLog(program_id_, info_log_len, NULL, prg_err);
	printf("%s\n", prg_err);

	glDeleteShader(vs_id);
	glDeleteShader(fs_id);
	delete[] vs_err;
	delete[] fs_err;
	delete[] prg_err;

}

shader_loader::~shader_loader(){

}
