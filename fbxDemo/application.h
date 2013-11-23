#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Application
{
public:
  Application(void);
  ~Application(void);
  virtual void init();
  virtual void run(Application* app);
  virtual void startup();
  virtual void render(double);
  virtual void shutdown();
  virtual void onResize(GLFWwindow*, int, int);
  virtual void onKey(GLFWwindow*, int, int, int, int);
  virtual void onMouseButton(GLFWwindow*, int, int, int);
  virtual void onMouseMove(GLFWwindow*, double, double);
  virtual void onMouseWheel(GLFWwindow*, double, double);
protected:
  static Application* app;
  static void glfw_onResize(GLFWwindow*, int, int);
  static void glfw_onKey(GLFWwindow*, int, int, int, int);
  static void glfw_onMouseButton(GLFWwindow*, int, int, int);
  static void glfw_onMouseMove(GLFWwindow*, double, double);
  static void glfw_onMouseWheel(GLFWwindow*, double, double);
  GLuint loadShader(const char*, GLenum);
};

