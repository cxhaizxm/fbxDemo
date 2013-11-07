#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include <GL/glew.h>
#include "shader.h"

GLuint loadShader(const char * shader_filename, GLenum shader_type)
{
  GLuint shader = glCreateShader(shader_type);
  string src;
  ifstream ifs(shader_filename, std::ios::in);
  if(ifs.is_open())
  {
    string line = "";
	  while(getline(ifs, line))
	  {
	    src += "\n" + line;
	  }
	  ifs.close();
  }

  const char * srcPtr = src.c_str();
  glShaderSource(shader, 1, &srcPtr, NULL);
  glCompileShader(shader);

  GLint result = GL_FALSE;
  int info_log_length = -1;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
  if(info_log_length > 0)
  {
    std::vector<char> errorMsg(info_log_length + 1);
    glGetShaderInfoLog(shader, info_log_length, NULL, &errorMsg[0]);
    printf("%s\n", &errorMsg[0]);
  }
  return shader;
}