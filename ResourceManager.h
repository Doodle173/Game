#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <GL/glew.h>

#include "Texture.h"
#include "Shader.h"

#include<SOIL2/SOIL2.h>

// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined.
class ResourceManager
{
public:
    // Resource storage
    static std::map<std::string, Shader>    Shaders;
    static std::map<std::string, Texture> Textures;
    // Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    static Shader   LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);
    // Retrieves a stored sader
    static Shader   GetShader(std::string name);
    // Loads (and generates) a texture from file
    static Texture LoadTexture(const GLchar* file, GLboolean alpha, std::string name);
    // Retrieves a stored texture
    static Texture GetTexture(std::string name);
    // Properly de-allocates all loaded resources
    static void      clear();
private:
    // Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() { }
    // Loads and generates a shader from file
    static Shader    loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);
    // Loads a single texture from file
    static Texture loadTextureFromFile(const GLchar* file, GLboolean alpha);
};

#endif