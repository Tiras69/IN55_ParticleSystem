#version 130


in vec3 fColor;
in vec2 Texcoord;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
  fragColor = texture(tex, Texcoord) * vec4( fColor, 1.0f );
}
