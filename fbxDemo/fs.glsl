#version 430 core

in Vertex {
  vec3 normal;
  vec3 color;
  vec3 view;
  vec3 L;
} vertex;

out vec4 color;

void main(void)
{
  color = vec4(vertex.color, 1.0);
}
