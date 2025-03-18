#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Game
{
    public:
        Game();
        ~Game();
        void Run();

    private:
        GLFWwindow* window;

        bool InitWindow();
        void InputHandling();
        void Update();
        void Render();
};

#endif