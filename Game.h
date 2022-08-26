#ifndef GAME_H
#define GAME_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<iostream>
#include<string>

#include "Camera.h"

#include "LineRenderer.h"

#include "ResourceManager.h"
#include "Shader.h"

#include "Chunk.h"

//Game State Management
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_PAUSE,
};



class Game
{
public:

	GameState State;
	GLboolean Keys[1024];
	GLuint Width, Height;

	Camera cam;

	LineRenderer *line_renderer;

	unsigned int VBO, VAO;

	Chunk *chunk;
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