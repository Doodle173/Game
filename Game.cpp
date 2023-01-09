#include "Game.h"

Game::Game(GLuint width, GLuint height) : Keys(), Width(width), Height(height) {
}

Game::~Game() {
}


void Game::init() {
    ResourceManager::LoadShader("./resources/shaders/test_vertex.glsl", "./resources/shaders/test_fragment.glsl", nullptr, "triangle_shader");
    this->triangle = Triangle();
    this->triangle.init(); 
}

void Game::ProcessInput(GLfloat dt) {
}

void Game::Update(GLfloat dt) {
}

void Game::Render() {
    this->triangle.render();
}


