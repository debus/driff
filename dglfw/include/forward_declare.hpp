#ifndef _INCLUDE_GUARD_A9343740_2F56_4CB9_B664_027745EB8C7D
#define _INCLUDE_GUARD_A9343740_2F56_4CB9_B664_027745EB8C7D

#include <GLFW/glfw3.h>

#define   DGLFW_MOUSE_BUTTON_1		GLFW_MOUSE_BUTTON1
#define   DGLFW_MOUSE_BUTTON_2		GLFW_MOUSE_BUTTON2
#define   DGLFW_MOUSE_BUTTON_3		GLFW_MOUSE_BUTTON3
#define   DGLFW_MOUSE_BUTTON_4		GLFW_MOUSE_BUTTON4
#define   DGLFW_MOUSE_BUTTON_5		GLFW_MOUSE_BUTTON5
#define   DGLFW_MOUSE_BUTTON_6		GLFW_MOUSE_BUTTON6
#define   DGLFW_MOUSE_BUTTON_7		GLFW_MOUSE_BUTTON7
#define   DGLFW_MOUSE_BUTTON_8		GLFW_MOUSE_BUTTON8
#define   DGLFW_MOUSE_BUTTON_LAST		GLFW_MOUSE_BUTTONLAST
#define   DGLFW_MOUSE_BUTTON_LEFT		GLFW_MOUSE_BUTTONLEFT
#define   DGLFW_MOUSE_BUTTON_RIGHT		GLFW_MOUSE_BUTTONRIGHT
#define   DGLFW_MOUSE_BUTTON_MIDDLE		GLFW_MOUSE_BUTTONMIDDLE

#define DGLFW_PRESS   GLFW_PRESS
#define DGLFW_RELEASE   GLFW_RELEASE

#define DGLFW_WINDOW_MOUSE_BUTTON_CALLBACK 0
#define DGLFW_WINDOW_KEY_CALLBACK (DGLFW_WINDOW_MOUSE_BUTTON_CALLBACK + 1)
#define DGLFW_WINDOW_CURSOR_POS_CALLBACK (DGLFW_WINDOW_KEY_CALLBACK + 1)
#define DGLFW_WINDOW_CLOSE_CALLBACK (DGLFW_WINDOW_CURSOR_POS_CALLBACK + 1)
#define DGLFW_WINDOW_REFRESH_CALLBACK (DGLFW_WINDOW_CLOSE_CALLBACK + 1)
#define DGLFW_WINDOW_FOCUS_CALLBACK (DGLFW_WINDOW_REFRESH_CALLBACK + 1)
#define DGLFW_WINDOW_SIZE_CALLBACK (DGLFW_WINDOW_FOCUS_CALLBACK + 1) 
#define DGLFW_WINDOW_POS_CALLBACK (DGLFW_WINDOW_SIZE_CALLBACK + 1)

#define DGLFW_WINDOW_POSITION_CHANGED 1
#define DGLFW_WINDOW_SIZE_CHANGED 2

#include "keys.hpp"

namespace debus{namespace dglfw{

  typedef GLFWvidmode DVideoMode;
  typedef GLFWgammaramp DGammaRamp;

  class DMonitor;

  typedef int MouseButton;
  typedef int ButtonAction; 
  typedef int ModifierKeys;
  typedef int KeyboardKey;
  typedef int ScanCode;

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

  };

  template<typename T>
    struct RectBase{
      T x,y;
      T width, height;

      template<typename D>
        operator RectBase<D>(){
          RectBase<D> ret;
          ret.x = (D)this->x;
          ret.y = (D)this->y;
          ret.width = (D)this->width;
          ret.height = (D)this->width;
          return ret;
        };
    };

  namespace window{
    class DWindowOptions;
    class DWindow;
    typedef RectBase<int> WindowRect;
  }; 


}};

#endif // _INCLUDE_GUARD_A9343740_2F56_4CB9_B664_027745EB8C7D

