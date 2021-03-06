
#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 mvp;
uniform float theta;

out vec3 my_color;

void main(){
  vec3 mod = vertexPosition_modelspace;
  float dx = 20 - mod.x;
  float dy = 20 - mod.y;
  float dist = sqrt(dx * dx + dy * dy);
  float ndist = theta - dist;
  mod.z = 2.5f / sqrt(dist) * sin(dist - theta);
	gl_Position = mvp * vec4(mod, 1);
  my_color = vec3(0.1f, 0.1f, ndist / 10.0f);
}
