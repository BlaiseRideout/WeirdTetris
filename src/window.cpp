#include "window.hpp"

#include <GL/glew.h>
#include <GL/glfw.h>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <glm/gtc/matrix_transform.hpp>

extern const GLubyte *gluErrorString(GLenum error);



Window::Window(int width, int height, bool fullscreen, std::string title, int majorVersion, int minorVersion) : width(width), height(height), fullscreen(fullscreen), title(title), majorVersion(majorVersion), minorVersion(minorVersion) {
  initGlfw(fullscreen);
  initGL();
}

Window::Window(int width, int height, bool fullscreen, std::string title) : Window(width, height, fullscreen, title, 3, 1) {
}

Window::Window(int width, int height, bool fullscreen) : Window(width, height, fullscreen, "Divamia", 3, 1) {
}

Window::Window(bool fullscreen) : Window(800, 600, fullscreen) {
}

Window::Window(int width, int height) : Window(width, height, false) {
}

Window::Window() : Window(false) {
}

Window::~Window() {
  glfwDestroyWindow(window);
}

void Window::clearColor(glm::vec4 color) {
  glfwMakeContextCurrent(this->window);
  glClearColor(color.r, color.g, color.b, color.a);
  glfwMakeContextCurrent(Window::currentWindow);
}

void Window::clearColor(glm::vec3 color) {
  clearColor(glm::vec4(color, 1.0f));
}

void Window::clearScreen() {
  glfwMakeContextCurrent(this->window);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwMakeContextCurrent(Window::currentWindow);
}

void Window::swapBuffers() {
  glfwSwapBuffers(this->window);
}

void Window::makeCurrent() {
  Window::currentWindow = this->window;
  glfwMakeContextCurrent(this->window);
}

bool Window::shouldClose() {
  return glfwWindowShouldClose(this->window);
}

void Window::shouldClose(bool should) {
  glfwSetWindowShouldClose(this->window, should?GL_TRUE:GL_FALSE);
}

void Window::initGL() {
  this->makeCurrent();
  glewExperimental = GL_TRUE;
  GLenum err = glewInit();
  if (GLEW_OK != err)
    throw std::runtime_error(std::string((const char *)glewGetErrorString(err)));

  glClearColor(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f, 0.0f);
  glViewport(0, 0, this->width, this->height);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::initGlfw(bool fullscreen) {
  //initialize glfw
  if (!glfwInit())
    throw std::runtime_error("Failed to initialize GLFW.");

  if(fullscreen)
    this->window = glfwCreateWindow(this->width, this->height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
  else
    this->window = glfwCreateWindow(this->width, this->height, title.c_str(), nullptr, nullptr);

  if(!this->window)
    throw std::runtime_error("Failed to open GLFW window.");

  glfwWindowHint(GLFW_OPENGL_VERSION_MAJOR, this->majorVersion);
  glfwWindowHint(GLFW_OPENGL_VERSION_MINOR, this->minorVersion);
  glfwWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
  glfwWindowHint(GLFW_FSAA_SAMPLES, 4);

  //vsync: 0 = no, 1 = yes
  glfwSwapInterval(1);

  std::cout << glGetString(GL_VERSION) << std::endl;
}

GLFWwindow *Window::currentWindow = nullptr;