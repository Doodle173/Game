#include<vector>

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

#include<iostream>

#include "ResourceManager.h"

#include <cstdint>

#include "byte4.h"
#include "world_defs.h"
class Chunk
{
public:
	uint8_t block_map[CX][CY][CZ];

	bool changed;
	int elements;

	unsigned int vbo, vao;

	std::vector<byte4> vertices;

	glm::mat4 model;

	Chunk();

	void init();
	void set_block(int x, int y, int z, uint8_t block_id);
	void update();
	int render();
};

