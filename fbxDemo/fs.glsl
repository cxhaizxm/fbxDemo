#version 430 core

in vec3 normal_fs;
in vec3 color_fs;
out vec4 color;

void main(void)
{
  color = vec4(color_fs, 1.0);
}
