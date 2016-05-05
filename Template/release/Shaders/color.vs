#version 130


uniform mat4 MVP;

in vec2 texcoord;
in vec3 position;
in vec3 color;

out vec3 fColor;
out vec2 Texcoord;

void main()
{
  gl_Position = MVP * vec4( position, 1.0f );

  Texcoord = texcoord;
  fColor = color;
}
