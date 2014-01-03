#ifndef _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00
#define _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00
#include <GLFW/glfw3.h>
namespace debus{namespace dglfw{

  namespace error_handling{
    enum ERROR_CODE{
      NOT_INITIALIZED = GLFW_NOT_INITIALIZED,
      NO_CURRENT_CONTEXT = GLFW_NO_CURRENT_CONTEXT,
      INVALID_ENUM = GLFW_INVALID_ENUM,
      INVALID_VALUE = GLFW_INVALID_VALUE,
      OUT_OF_MEMORY = GLFW_OUT_OF_MEMORY,
      API_UNAVAILABLE = GLFW_API_UNAVAILABLE,
      VERSION_UNAVAILABLE = GLFW_VERSION_UNAVAILABLE,
      PLATFORM_ERROR = GLFW_PLATFORM_ERROR,
      FORMAT_UNAVAILABLE = GLFW_FORMAT_UNAVAILABLE
    };

    typedef void(*DGLFWerrorfun)(ERROR_CODE, const char*);

    DGLFWerrorfun setErrorCallback(DGLFWerrorfun cbfun){
      return (DGLFWerrorfun) glfwSetErrorCallback((GLFWerrorfun)cbfun);
    };

  };


}};

#endif // _INCLUDE_GUARD_C0785670_5902_4584_89BE_33FEBEFAEF00
