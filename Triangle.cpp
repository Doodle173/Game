#include "Triangle.h"


Triangle::Triangle()
{
    
}

void Triangle::init()
{
    std::cout << "triangle init func called" << std::endl;

    this->color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    unsigned int vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    ResourceManager::GetShader("triangle_shader").setVector4f("color", this->color, true);
}

void Triangle::render()
{
    ResourceManager::GetShader("triangle_shader").Use();
    glBindVertexArray(this->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
