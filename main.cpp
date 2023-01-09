#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "Game.h"
#include "ResourceManager.h"

//GLFW keyhandling declerations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window,  double xpos,  double ypos);
//window width
const GLuint SCREEN_WIDTH = 800;
//window height
const GLuint SCREEN_HEIGHT = 600;

Game game(SCREEN_WIDTH, SCREEN_HEIGHT);

float last_x = SCREEN_WIDTH / 2.0f;
float last_y = SCREEN_HEIGHT / 2.0f;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    glfwInit();
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    else {
        std::cout << "GLFW & Window Initialized Properly." << std::endl;
    }

    /* Make the window's context current */




    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cout << "GLEW failed to initialize.";
        std::cout << err;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window,  mouse_callback);
    //opengl config
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    game.init();

    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    float currentTime = 0.0f;
    float frameCounter = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        //calculate delta 
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        currentTime += deltaTime;

        float fps = frameCounter / currentTime;

        if (currentTime >= 1) {
            frameCounter = 0;
            currentTime = 0;
        }
        frameCounter++;


        glfwPollEvents();
        //deltatime = 0.001f;

        //manage input
        game.ProcessInput(deltaTime);

        //Update Game State
        game.Update(deltaTime);

        //render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.Render();


        glfwSwapBuffers(window);


    }

    //delete all resources from resource manager
    ResourceManager::clear();

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            game.Keys[key] = GL_TRUE;
        }
        else if (action == GLFW_RELEASE) {
            game.Keys[key] = GL_FALSE;
        }

        if (key == GLFW_KEY_ESCAPE) {
            //delete all resources from resource manager
            ResourceManager::clear();

            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
}