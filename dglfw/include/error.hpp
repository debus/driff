#ifndef _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00
#define _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00
#include "forward_declare.hpp"

namespace debus{namespace dglfw{

  namespace error_handling{

    DGLFWerrorfun setErrorCallback(DGLFWerrorfun cbfun){
      return (DGLFWerrorfun) glfwSetErrorCallback((GLFWerrorfun)cbfun);
    };

  };


}};

#endif // _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00

