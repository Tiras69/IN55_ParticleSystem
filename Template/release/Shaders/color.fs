#version 150 core

in vec3 fColor;
in vec2 TexCoord;

uniform float opacity;
uniform sampler2D image;

out vec4 fragColor;

void main()
{
  fragColor = vec4(texture(image, TexCoord).rgb * fColor.rgb, opacity);
}
