#ifndef GAME_H
#define GAME_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<string>

#include "Camera.h"

#include "ResourceManager.h"
#include "Shader.h"

#include "Triangle.h"

class Game
{
public:
	
	Triangle triangle;

	GLboolean Keys[1024];
	GLuint Width, Height;

	Camera cam;

	//Game Constructor & Deconstructor
	Game(GLuint width, GLuint height);
	~Game();

	//Game Init Function
	void init();

	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();

private:
};

#endif