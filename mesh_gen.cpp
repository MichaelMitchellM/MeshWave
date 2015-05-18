
#include "mesh_gen.hpp"

mesh_gen::mesh_gen(unsigned width, unsigned height, float lod){

	width_  = width;
	height_ = height;

	mesh_ = new float[18u * width * height];

	num_bytes_ = 4u * 18u * width * height;
	num_verts_ = 6u * width * height;
	num_tris_  = 2u * width * height;

	auto index = 0u;
	for (auto y = 0u; y < height; ++y){

		for (auto x = 0u; x < width; ++x){

			// triangle 1
			mesh_[18u * index + 0u] = (float)(x)      * lod;
			mesh_[18u * index + 1u] = (float)(y + 1u) * lod;
			mesh_[18u * index + 2u] = 0.0f;

			mesh_[18u * index + 3u] = (float)(x) * lod;
			mesh_[18u * index + 4u] = (float)(y) * lod;
			mesh_[18u * index + 5u] = 0.0f;

			mesh_[18u * index + 6u] = (float)(x + 1u) * lod;
			mesh_[18u * index + 7u] = (float)(y)      * lod;
			mesh_[18u * index + 8u] = 0.0f;

			// triangle 2
			mesh_[18u * index + 9u ] = (float)(x)      * lod;
			mesh_[18u * index + 10u] = (float)(y + 1u) * lod;
			mesh_[18u * index + 11u] = 0.0f;

			mesh_[18u * index + 12u] = (float)(x + 1u) * lod;
			mesh_[18u * index + 13u] = (float)(y)      * lod;
			mesh_[18u * index + 14u] = 0.0f;

			mesh_[18u * index + 15u] = (float)(x + 1u) * lod;
			mesh_[18u * index + 16u] = (float)(y + 1u) * lod;
			mesh_[18u * index + 17u] = 0.0f;

			++index;
		}

	}

}

mesh_gen::~mesh_gen(){



}
