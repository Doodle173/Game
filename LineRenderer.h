#include<vector>

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

#include "ResourceManager.h"

class LineRenderer
{

unsigned int vbo, vao;


std::vector<float> vertices;
public:
	glm::mat4 model;

	LineRenderer();

	void add_line(glm::vec3 start_point, glm::vec3 end_point);
	int render();
private:

};

