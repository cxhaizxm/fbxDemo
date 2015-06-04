#version 430 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;

out Vertex
{
  vec3 normal;
  vec3 color;
  vec3 view;
} vertex;

out vec3 L;
out vec3 V;

uniform mat4 mv_matrix;
uniform mat3 n_matrix;
uniform mat4 proj_matrix;

uniform vec3 light_pos = vec3(100.0, 100.0, 100.0);

void main(void)
{
  vec4 pos_vs = mv_matrix * position;
  vertex.normal = normalize(mat3(n_matrix) * normal);
  L = light_pos - pos_vs.xyz;
  V = -pos_vs.xyz;
  vertex.view = normalize(V);
  gl_Position = proj_matrix * pos_vs;
}
