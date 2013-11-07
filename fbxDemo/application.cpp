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

void Application::onResize(int x, int y)
{
}

void Application::onKey(int key, int action)
{
}

void Application::onMouseButton(int button, int action)
{
}

void Application::onMouseMove(int x, int y)
{
}

void Application::onMouseWheel(int pos)
{
}

void Application::glfw_onKey(int key, int action)
{
  app->onKey(key, action);
}

void Application::glfw_onMouseButton(int button, int action)
{
  app->onMouseButton(button, action);
}

void Application::glfw_onMouseMove(int x, int y)
{
  app->onMouseMove(x, y);
}

void Application::glfw_onMouseWheel(int pos)
{
  app->onMouseWheel(pos);
}

Application* Application::app = 0;