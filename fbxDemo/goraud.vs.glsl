#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;

out Vertex
{
  vec3 normal;
  vec3 color;
  vec3 view;
} vertex;

uniform mat4 mv_matrix;
uniform mat3 n_matrix;
uniform mat4 proj_matrix;

// light / material properties
uniform vec3 light_pos = vec3(100.0, 100.0, 100.0);
uniform vec3 diffuse_albedo = vec3(0.1, 0.23, 0.5);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0;

uniform vec3 rim_color;
uniform float rim_power = 16.0;

vec3 calculate_rim(vec3 N, vec3 V)
{
  float f = 1.0 - dot(N, V);
  f = smoothstep(0.0, 1.0, f);
  f = pow(f, rim_power);
  return f * rim_color;
}

void main(void)
{
  vec4 pos_vs = mv_matrix * position;
  vec3 N = n_matrix * normal;
  vec3 L = light_pos - position.xyz;
  vec3 V = -pos_vs.xyz;
  vertex.view = V;

  N = normalize(N);
  L = normalize(L);
  V = normalize(V);

  vec3 R = reflect(-L, N);
  vec3 diffuse = max(dot(N, L), 0.0) * diffuse_albedo;
  vec3 specular = pow(max(dot(R, V), 0.0), specular_power) * specular_albedo;
  vec3 rim_lighting = calculate_rim(N, V);

  vertex.color = diffuse + specular + rim_lighting;
  vertex.normal = n_matrix * normal;

  gl_Position = proj_matrix * pos_vs;

}
