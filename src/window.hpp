#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Window {
  public:
    Window(int width, int height, bool fullscreen, std::string title, int majorVersion, int minorVersion);
    Window(int width, int height, bool fullscreen, std::string title);
    Window(int width, int height, bool fullscreen);
    Window(bool fullscreen);
    Window(int width, int height);
    Window();
    virtual ~Window();
    operator GLFWwindow*();
    void clearColor(glm::vec3 color);
    void clearColor(glm::vec4 color);
    void clearScreen();
    void swapBuffers();
    void makeCurrent();
    bool shouldClose();
    void shouldClose(bool should);
    int getKey(int key);

    int width;
    int height;
    bool fullscreen;
    std::string title;
    int majorVersion;
    int minorVersion;
  private:
    void initGL();
    void initGlfw();

    GLFWwindow *window;
    static GLFWwindow *currentWindow;
};

#endif
