#pragma once
#include "application.h"
#include "vmath.h"
#include <fbxsdk.h>
class fbxDemoApp :
  public Application
{
public:
  fbxDemoApp(void);
  ~fbxDemoApp(void);
  virtual void onMouseButton(GLFWwindow*,int,int,int);
  virtual void onMouseMove(GLFWwindow*,double,double);
  virtual void render(double);
  virtual void startup(void);
  virtual void shutdown(void);
  GLuint compile_shaders(void);
  void loadFromFBX(const char*);
  void loadVBO(void);
  void traverseFBXNodes(FbxNode*);
  void setGeometry(GLfloat*,int);
  void setIndexBuffer(GLuint*,int);
protected:
  bool rotationEnabled;
  bool translationEnabled;

  double mouse_x, mouse_y;
  double mouse_base_x, mouse_base_y;
  float rot_x, rot_y;
  float tran_x, tran_y;
  vmath::mat4 mv_matrix;
  vmath::mat4 proj_matrix;
  int num_vertices;
  int num_indices;
  GLfloat* vertex_data;
  GLuint* vertex_indices;
  GLuint vao;
  GLuint vertex_vbo;
  GLuint index_vbo;

  GLuint program;
  GLuint mv_location;
  GLuint proj_location;
};

