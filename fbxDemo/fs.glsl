#version 430 core

in vec3 normal_fs;
out vec4 color;

void main(void)
{
  vec3 n = normalize(normal_fs);
  vec4 c = vec4(1.0, -1.0, 0.0, 0.0) * n.z + vec4(0.0, 0.0, 0.0, 1.0);
  color = clamp(c, vec4(0.0), vec4(1.0));
}
