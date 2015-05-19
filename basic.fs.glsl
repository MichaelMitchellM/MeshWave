
#version 330 core

uniform vec3 in_color;

in vec3 my_color;

out vec3 color;

void main(){
  color = my_color;
  if(in_color.x == 0.0f){
      color.z = my_color.x;
      color.y = my_color.z;
      color.x = my_color.y;
  }
}
