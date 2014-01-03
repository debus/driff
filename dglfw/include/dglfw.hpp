#ifndef DEBUS_H_GRAPHICS_H_SUBED
#define DEBUS_H_GRAPHICS_H_SUBED
#include <string.h> 
#include <vector>
#include "window.hpp"
#include "error.hpp"
#include "input.hpp"
namespace debus{namespace dglfw{
  int dglfwInit(){
    return glfwInit();
  }

  void dglfwTerminate(){
    glfwTerminate();
  }

}};

#endif
