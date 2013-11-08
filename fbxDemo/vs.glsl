#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;

out vec3 normal_fs;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

void main(void)
{
  vec4 pos_vs = mv_matrix * position;
  normal_fs = normal;
  gl_Position = proj_matrix * pos_vs;
}
