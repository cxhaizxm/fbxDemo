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
  virtual void onMouseButton(int, int);
  virtual void onMouseMove(int, int);
  virtual void onMouseWheel(int);
protected:
  static Application* app;
  static void glfw_onResize(int, int);
  static void glfw_onKey(int, int);
  static void glfw_onMouseButton(int, int);
  static void glfw_onMouseMove(int, int);
  static void glfw_onMouseWheel(int);
};

