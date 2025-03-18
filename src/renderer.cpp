#include "renderer.h"
#include <GLFW/glfw3.h>

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}