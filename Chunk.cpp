#include "Chunk.h"

Chunk::Chunk()
{
	memset(block_map, 0, sizeof(block_map));
	elements = 0;
	changed = true;
	init();

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Chunk::init()
{
	for (int x = 0; x < CX; x++) {
		for (int y = 0; y < CY; y++) {
			for (int z = 0; z < CX; z++) {
				block_map[x][y][z] = 1;
			}
		}
	}
}

void Chunk::set_block(int x, int y, int z, uint8_t block_id)
{
	block_map[x][y][z] = block_id;
}

void Chunk::update()
{
	changed = false;
	//byte4 vertices[CX * CY * CX * 6 * 6];
	int i = 0;

	for (int x = 0; x < CX; x++) {
		for (int y = 0; y < CY; y++) {
			for (int z = 0; z < CX; z++) {
				uint8_t block_id = block_map[x][y][z];

				//negative x

				vertices.push_back(byte4(x, y, z, block_id));
				vertices.push_back(byte4(x, y, z + 1, block_id));
				vertices.push_back(byte4(x, y + 1, z, block_id));
				vertices.push_back(byte4(x, y + 1, z, block_id));
				vertices.push_back(byte4(x, y, z + 1, block_id));
				vertices.push_back(byte4(x, y + 1, z + 1, block_id));

				//positive x
				vertices.push_back(byte4(x + 1, y, z, block_id));
				vertices.push_back(byte4(x + 1, y + 1, z, block_id));
				vertices.push_back(byte4(x + 1, y, z + 1, block_id));
				vertices.push_back(byte4(x + 1, y + 1, z, block_id));
				vertices.push_back(byte4(x + 1, y + 1, z + 1, block_id));
				vertices.push_back(byte4(x + 1, y, z + 1, block_id));

				//negative z
				vertices.push_back(byte4(x, y, z, block_id));
				vertices.push_back(byte4(x, y + 1, z, block_id));
				vertices.push_back(byte4(x + 1, y, z, block_id));
				vertices.push_back(byte4(x, y + 1, z, block_id));
				vertices.push_back(byte4(x + 1, y + 1, z, block_id));
				vertices.push_back(byte4(x + 1, y, z, block_id));

				//positive z
				vertices.push_back(byte4(x, y, z+1, block_id));
				vertices.push_back(byte4(x+1, y, z+1, block_id));
				vertices.push_back(byte4(x, y+1, z+1, block_id)); 
				vertices.push_back(byte4(x, y + 1, z + 1, block_id));
				vertices.push_back(byte4(x + 1, y, z + 1, block_id));
				vertices.push_back(byte4(x + 1, y + 1, z + 1, block_id));
			}
		}
	}

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	std::cout << vertices.data();
}

int Chunk::render()
{

	if (changed) {
		update();
	}
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 4, GL_BYTE, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	return 0;
}
