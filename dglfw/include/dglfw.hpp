#ifndef _INCLUDE_GUARD_7FC0379A_2760_400C_AD36_0F4502D626DA
#define _INCLUDE_GUARD_7FC0379A_2760_400C_AD36_0F4502D626DA

#include <string.h> 
#include <vector>
#include "window.hpp"
#include "monitor.hpp"
#include "error.hpp"
namespace debus{namespace dglfw{

  void dglfwTerminate();

  int dglfwInit(){
    int ret = glfwInit();
    if(!ret)
      dglfwTerminate();
    return ret;
  }

  void dglfwTerminate(){
    glfwTerminate();
  }

}};

#endif // _INCLUDE_GUARD_7FC0379A_2760_400C_AD36_0F4502D626DA

