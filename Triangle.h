#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "Shader.h"
#include "ResourceManager.h"
#include "glm/glm.hpp"

class Triangle
{
public:
	
	unsigned int vao;
	glm::vec4 color;

	Triangle();
	
	void init();
	void render();
};

