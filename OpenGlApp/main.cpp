#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Windows dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{

    // Initialise GLFW
    if (!glfwInit()) {
        printf("GLFW Initialisation failed!");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW windows
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Disable backward compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Enable forward compatibilityy
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test window", NULL, NULL);
    if (!mainWindow) {
        printf("GLFW windows creation failed!");
        glfwTerminate();
        return 1;
    }

    // Buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set GLEW context 
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK) {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glViewport(0, 0, bufferWidth, bufferHeight);

    // Loop unitl windows closed
    while (!glfwWindowShouldClose(mainWindow)) {
        // Handle user input
        glfwPollEvents();

        // Clear Window
        glClearColor(1.0f, 1.0f, 1.0f,  1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }
    return 0;
}

