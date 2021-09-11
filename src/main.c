// Main File of Heroes Headland, initializing the window etc. Mainly boilerplate stuff //
// This hase a lot of comments, so beginners know what they're looking at, and also giving reason to certain parts of the program. //

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

int main()
{
    glfwInit();
    
    // Hints for glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // Hinting the major version of glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  // Hinting the minor version of glfw
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // Hinting the profile of OpenGL to use. In this case we want the newest functions, so the core profile

    // Creating the window
    GLFWwindow* wnd = glfwCreateWindow(
            800, 600,                                               // Width and Height, initially just vga size
            "Heroes Headland",                                      // Title
            NULL,                                                   // Don't need fullscreen, no
            NULL                                                    // Window to share with, no
    );
    if (!wnd)
    {
        printf("HH error(1): Failed to create window\n", "%s");     // Gives user error code and reason
        glfwTerminate();                                            // Terminates the program
        return 1;                                                   // Returns the error code
    }

    glfwMakeContextCurrent(wnd);                                    // Sets the window created as the one that shall be used

    gladLoadGL();                                                   // Telling glad to load the needed configs for OpenGL

    glViewport(                                                     // The viewport is what will be rendered to the user
            0, 0,                                                   // It goes from top-left
            800, 600                                                // To bottom-right
            );                                                      // We are not doing anything fancy with the viewport so it is just filling up the window

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                           // Logically, just setting the clearing color to black
    glClear(GL_COLOR_BUFFER_BIT);                                   // Clearing the screen with the color buffer bit
    glfwSwapBuffers(wnd);                                           // Part of the rendering pipeline, just swapping the back buffer with the front

    while (!glfwWindowShouldClose(wnd))                             // While the user themselves doesn't close the window
    {
        glfwPollEvents();                                           // Process all of the window specific tasks
    }

    glfwDestroyWindow(wnd);                                         // Must destroy the window when the program is done
    glfwTerminate();                                                // Finally, ending the program before returning
    return 0;
}
