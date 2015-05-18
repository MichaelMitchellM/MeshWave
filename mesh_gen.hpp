
#pragma once

#include <map>

class mesh_gen{

private:
	unsigned width_;
	unsigned height_;

	unsigned num_bytes_;
	unsigned num_verts_;
	unsigned num_tris_;

	float* mesh_;

public:
	mesh_gen(unsigned width, unsigned height, float lod);
	~mesh_gen();

	unsigned width() { return width_;  }
	unsigned height(){ return height_; }

	unsigned num_bytes(){ return num_bytes_; }
	unsigned num_verts(){ return num_verts_; }
	unsigned num_tris() { return num_tris_;  }

	float* mesh(){ return mesh_; }

};
