#pragma once
#include "application.h"
#include <fbxsdk.h>
class fbxDemoApp :
  public Application
{
public:
  fbxDemoApp(void);
  ~fbxDemoApp(void);
  virtual void startup(void);
  void loadFromFBX(const char*);
  void loadVBO(void);
  void traverseFBXNodes(FbxNode*);
  void setGeometry(GLfloat*,int);
  void setIndexBuffer(GLuint*,int);
protected:
  int num_vertices;
  int num_indices;
  GLfloat* vertex_data;
  GLuint*  vertex_indices;
  GLuint vao;
  GLuint vertex_vbo;
  GLuint index_vbo;
};

