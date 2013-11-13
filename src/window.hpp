#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <glm/glm.hpp>

class Window {
  public:
    Window(int width, int height, bool fullscreen, std::string title, int majorVersion, int minorVersion);
    Window(int width, int height, bool fullscreen, std::string title);
    Window(int width, int height, bool fullscreen);
    Window(bool fullscreen);
    Window(int width, int height);
    Window();
    virtual ~Window();
    void clearColor(glm::vec3 color);
    void clearColor(glm::vec4 color);
    void clearScreen();
    void swapBuffers();
    void makeCurrent();
    bool shouldClose();
    void shouldClose(bool should);

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
