#include <stdio.h>
#include <stdlib.h>
#include "graphics.hpp"

using namespace debus::graphics;

int main(int argc, char** argv){

  if(!glfwInit()){
    fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  window_options_t opts;
  opts.hints.fsaa_samples = 4;
  opts.hints.opengl_version_major = 1;
  opts.hints.opengl_version_minor = 1;
  //opts.hints.profile = GLFW_OPENGL_CORE_PROFILE;

  opts.width = 1024;
  opts.height = 768;
  opts.depthbits = 32;
  printf("%u\n",GLFW_REFRESH_RATE);
  if(!open_window(&opts)){
    fprintf(stderr, "Failed to open window!\n");
    return -1;
  }
  
  return 0;
}
