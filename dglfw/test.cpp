#include <stdio.h>
#include <stdlib.h>
#include "dglfw.hpp"

using namespace debus::dglfw;

int main(int argc, char** argv){
  if(!DGLFWInit()){
    fprintf(stderr, "Failed to initialize DWindow\n");
    return 1;
  } 
  return 0;
}
