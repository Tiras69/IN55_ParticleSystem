#version 150 core


uniform mat4 MVP;

in vec3 position;
in vec3 color;
in vec2 texcoord;

out vec2 TexCoord;
out vec3 fColor;

void main()
{
  gl_Position = MVP * vec4( position, 1.0f );
  TexCoord = texcoord;
  fColor = color;
}
