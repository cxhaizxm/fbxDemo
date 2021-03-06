#pragma once
#include "application.h"
#include <fbxsdk.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum ShaderProgram {
  GORAUD,
  PHONG,
  BLINNPHONG,
  TOON
};

class fbxDemoApp :
  public Application
{
public:
  fbxDemoApp(void);
  ~fbxDemoApp(void);
  virtual void onKey(GLFWwindow*, int, int, int, int);
  virtual void onMouseButton(GLFWwindow*, int, int, int);
  virtual void onMouseMove(GLFWwindow*, double, double);
  virtual void onMouseWheel(GLFWwindow*, double, double);
  virtual void onResize(GLFWwindow*, int, int);
  virtual void render(double);
  virtual void startup(void);
  virtual void shutdown(void);
  void compile_shaders(void);
  void loadFromFBX(const char*);
  void loadVBO(void);
  void traverseFBXNodes(FbxNode*);
  void setGeometry(GLfloat*,int);
  void setIndexBuffer(GLuint*,int);
  void setNormals(GLfloat*,int);
protected:
  // Window information
  int w, h;
  float aspect;

  bool wireframe_mode;
  // Toggles for translation modes
  bool rotationEnabled;
  bool translationEnabled;
  bool rim_lighting;
  bool outlining;
  // Mouse coordinates for translation
  double mouse_x, mouse_y;
  double mouse_base_x, mouse_base_y;
  // Translation values
  float rot_x, rot_y;
  float tran_x, tran_y;
  float zoom;
  // Uniform matrices
  glm::mat4 mv_matrix;
  glm::mat4 proj_matrix;
  
  int num_vertices;
  int num_indices;
  int num_normals;

  GLfloat* vertex_data;
  GLuint* vertex_indices;
  GLfloat* vertex_normals;
  GLuint vao;
  GLuint vertex_vbo;
  GLuint index_vbo;
  GLuint normals_vbo;
  GLuint cel_texture;

  GLuint goraud_program;
  GLuint outline_program;
  GLuint phong_program;
  GLuint blinnphong_program;
  GLuint cel_program;
  GLuint current_program;

  ShaderProgram shader_choice;

  GLuint mv_location;
  GLuint n_location;
  GLuint proj_location;
  GLuint rimcolor_location;

};

