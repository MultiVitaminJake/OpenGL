#include "game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Game constructor
Game::Game()
{
    if(!InitWindow())
    {
        std::cerr << "Failed to initialize the window!\n";
    }
}

// Game deconstructor
Game::~Game()
{
    glfwTerminate();
}

// Initialize window
bool Game::InitWindow()
{
    if (!glfwInit()) // Return error if GLFW failed to initialize
    {
        std::cerr << "Failed to initialize GLFW!\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Sets the major version of OPENGL (3) - 3.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Sets the minor version of OPENGL (3) - 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "Block Breaker", NULL, NULL); // Create Window
    if(!window) // Return error if the Window failed to be created
    {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate(); // Terminate GLFW proccess
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // Return error if glad fails to initialize
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glViewport(0, 0, 800, 600);
    return true;
}

// Runs the main game loop
void Game::Run()
{
    while(!glfwWindowShouldClose(window))
    {
        InputHandling();
        Update();
        Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

// TODO: Handles the players input
void Game::InputHandling()
{

}

// TODO: Updates game logic
void Game::Update()
{

}

// TODO: Renders the game
void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}