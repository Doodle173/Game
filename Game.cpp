#include "Game.h"


Game::Game(GLuint width, GLuint height) : State(GAME_ACTIVE), Keys(), Width(width), Height(height) {

}

Game::~Game() {


}


void Game::init() {

	ResourceManager::LoadShader("resources/shaders/chunk_vert.glsl", "resources/shaders/chunk_frag.glsl", nullptr, "line_shader");
	ResourceManager::LoadTexture("resources/textures/atlas_v2.4.png", true, "atlas");

	cam = Camera();
 
	//line_renderer = new LineRenderer();
	chunk = new Chunk();
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	//view = glm::translate();


	projection = glm::perspective(glm::radians(45.0f), (float)Width / (float)Height, 0.1f, 1000.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	ResourceManager::GetShader("line_shader").setMatrix4("projection", projection, true);
	ResourceManager::GetShader("line_shader").setMatrix4("view", view, true);
	ResourceManager::GetShader("line_shader").setMatrix4("model", chunk->model, true);
	//for (int x= 0; x <= 10; x++) {
		//line_renderer->add_line(glm::vec3(0, x, 0), glm::vec3(10, x, 0));
	//}

	//for (int y = 0; y <= 10; y++) {
		//line_renderer->add_line(glm::vec3(y, 0, 0), glm::vec3(y, 10, 0));
	//}
	chunk->update();
	
	

}
void Game::ProcessInput(GLfloat dt) {

	cam.update_position(); 
	if (Keys[GLFW_KEY_S]) {
		cam.Position.z += 1;
		cam.update_position();
	}

	if (Keys[GLFW_KEY_W]) {
		cam.Position.z -= 1;
		cam.update_position();
	}
	if (Keys[GLFW_KEY_A]) {
		cam.Position.x -= 1;
		cam.update_position();
	}

	if (Keys[GLFW_KEY_D ]) {
		cam.Position.x += 1;
		cam.update_position();
	}

	if (Keys[GLFW_KEY_SPACE]) {
		cam.Position.y += 1;
		cam.update_position();
	}

	if (Keys[GLFW_KEY_LEFT_SHIFT]) {
		cam.Position.y -= 1;
		cam.update_position();
	}
}

void Game::Update(GLfloat dt) {
}

void Game::Render() {
	//line_renderer->render();
	ResourceManager::GetTexture("atlas").Bind();
	chunk->render();
}


