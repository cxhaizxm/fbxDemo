#version 430 core

in vec3 normal_fs;
in vec3 L;
in vec3 V;

out vec4 color;

// Material properties
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
  vec3 N_fs = normalize(normal_fs);
  vec3 L_fs = normalize(L);
  vec3 V_fs = normalize(V);

  vec3 R = reflect(-L_fs, N_fs);

  vec3 diffuse = max(dot(N_fs, L_fs), 0.0) * diffuse_albedo;
  vec3 specular = pow(max(dot(R, V_fs), 0.0), specular_power) * specular_albedo;
  vec3 rim_lighting = calculate_rim(N_fs, V_fs);
  color = vec4(diffuse + specular + rim_lighting, 1.0);
}

