#include "LineRenderer.h"

LineRenderer::LineRenderer()
{

	std::vector<float> temp = {};
	vertices.insert(vertices.end(), temp.begin(), temp.end());
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f,-3.0f));
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void LineRenderer::add_line(glm::vec3 start_point, glm::vec3 end_point)
{
	std::vector<float> line_vertices = {
		start_point.x, start_point.y, start_point.z,
		end_point.x, end_point.y, end_point.z
	};

	vertices.insert(vertices.end(), line_vertices.begin(), line_vertices.end());
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

}

int LineRenderer::render()
{	
	glBindVertexArray(vao);
	glDrawArrays(GL_LINES, 0, vertices.size() / 3);
	return 0;
}


