#version 430

layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

in Vertex
{
  vec3 normal;
  vec3 color;
  vec3 view;
} vertex[];

out vec3 normal_gs;
out vec3 color_gs;

uniform float line_width = 0.0001;

void main(void) 
{
  int i;

  for(i = 0; i < gl_in.length(); i++)
  {
    gl_Position = gl_in[i].gl_Position + line_width * vec4(vertex[i].normal, 0.0);
    color_gs = vec3(0,0,0);
    normal_gs = vertex[i].normal;
    
    float dot_product = dot(-vec3(vertex[i].view), normal_gs);
    if(dot_product >= 0.0) {
      EmitVertex();
    }
  }
  EndPrimitive();
}
