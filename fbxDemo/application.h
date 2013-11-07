#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

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
  virtual void onResize(int, int);
  virtual void onKey(int, int);
  virtual void onMouseButton(GLFWwindow*, int, int, int);
  virtual void onMouseMove(GLFWwindow*, double, double);
  virtual void onMouseWheel(int);
protected:
  static Application* app;
  static void glfw_onResize(int, int);
  static void glfw_onKey(int, int);
  static void glfw_onMouseButton(GLFWwindow*, int, int, int);
  static void glfw_onMouseMove(GLFWwindow*, double, double);
  static void glfw_onMouseWheel(int);
};

