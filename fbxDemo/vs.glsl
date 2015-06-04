#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;

out vec3 normal_fs;

uniform mat4 mv_matrix;
uniform mat3 n_matrix;
uniform mat4 proj_matrix;

void main(void)
{
  vec4 pos_vs = mv_matrix * position;
  view_fs = pos_vs;
  normal_fs = proj_matrix * n_matrix * normal;
  gl_Position = proj_matrix * pos_vs;
}
