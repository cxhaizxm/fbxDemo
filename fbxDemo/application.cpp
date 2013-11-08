#include "application.h"


Application::Application(void)
{
}


Application::~Application(void)
{
}

void Application::init()
{
}

void Application::run(Application* the_app)
{
  bool running = true;
  app = the_app;
  if( !glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW!\n");
    exit(-1);
  }

  GLFWwindow* window;

  window = glfwCreateWindow(800, 600, "OpenGL Demo", NULL, NULL);
  glfwMakeContextCurrent(window);

  glewExperimental = true;
  if (glewInit() != GLEW_OK)
  {
    fprintf(stderr, "Failed to initalize GLEW!\n");
    exit(-1);
  }

  glfwSetMouseButtonCallback(window, glfw_onMouseButton);
  glfwSetCursorPosCallback(window, glfw_onMouseMove);
  glfwSetScrollCallback(window, glfw_onMouseWheel);
  glfwSetKeyCallback(window, glfw_onKey);
  glfwSetWindowSizeCallback(window, glfw_onResize);

  startup();
  do
  {
    render(glfwGetTime());

    running &= (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE);
    glfwPollEvents();
    glfwSwapBuffers(window);
  } while(running);

  shutdown();
  glfwTerminate();
}

void Application::render(double currentTime)
{
}

void Application::startup(void)
{
}

void Application::shutdown(void)
{
}

void Application::onResize(GLFWwindow* window, int x, int y)
{
}

void Application::onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void Application::onMouseButton(GLFWwindow* window, int button, int action, int mods)
{
}

void Application::onMouseMove(GLFWwindow* window, double x, double y)
{
}

void Application::onMouseWheel(GLFWwindow* window, double xoffset, double yoffset)
{
}

void Application::glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  app->onKey(window, key, scancode, action, mods);
}

void Application::glfw_onMouseButton(GLFWwindow* window, int button, int action, int mods)
{
  app->onMouseButton(window, button, action, mods);
}

void Application::glfw_onMouseMove(GLFWwindow* window, double x, double y)
{
  app->onMouseMove(window, x, y);
}

void Application::glfw_onMouseWheel(GLFWwindow* window, double xoffset, double yoffset)
{
  app->onMouseWheel(window, xoffset, yoffset);
}

void Application::glfw_onResize(GLFWwindow* window, int w, int h)
{
  app->onResize(window, w, h);
}

Application* Application::app = 0;