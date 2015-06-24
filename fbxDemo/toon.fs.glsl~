#version 430 core
uniform sampler1D cel_sampler;

in Vertex
{
  vec3 normal;
  vec3 color;
  vec3 view;
  vec3 L;
} vertex;

uniform float inner_line_width = 0.15;

out vec4 color;

void main(void) 
{
  vec3 N_fs = normalize(vertex.normal);
  vec3 L_fs = normalize(vertex.L);

  float tc = pow(max(0.0, dot(N_fs, L_fs)), 2.0);

  color = texture(cel_sampler, tc);
}
