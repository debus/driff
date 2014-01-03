#ifndef DEBUS_H_WINDOW_H_SUBED
#define DEBUS_H_WINDOW_H_SUBED
#include <string.h> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <map>
#include "monitor.hpp"
namespace debus{namespace dglfw{namespace window{

class DWindowOptions{
  std::map<int,int> setOptions;
public:

  DWindowOptions(){};

  void setWindowResizable(bool resizable){ setOptions[GLFW_RESIZABLE] = resizable ? GL_TRUE : GL_FALSE; };
  void setWindowInitiallyVisible(bool visible){ setOptions[GLFW_VISIBLE] = visible ? GL_TRUE : GL_FALSE; };
  void setWindowDecorated(bool decorated){ setOptions[GLFW_DECORATED] = decorated ? GL_TRUE : GL_FALSE; };
  void setDepthBits(int depth){ setOptions[GLFW_DEPTH_BITS] = depth; };
  void setStencilBits(int stencil){ setOptions[GLFW_STENCIL_BITS] = stencil; }
  void setForwardCompatible(bool compat){ setOptions[GLFW_OPENGL_FORWARD_COMPAT] = compat ? GL_TRUE : GL_FALSE; };
  void setDebugContext(bool debug){ setOptions[GLFW_OPENGL_DEBUG_CONTEXT] = debug ? GL_TRUE : GL_FALSE; };
  void setAuxBuffers(int auxBuffers){ setOptions[GLFW_AUX_BUFFERS] = auxBuffers; };
  void setSamples(int samples){ setOptions[GLFW_SAMPLES] = samples; };
  void setRefreshRate(int rate){ setOptions[GLFW_REFRESH_RATE] = rate; };
  void setStereo(bool stereo){ setOptions[GLFW_STEREO] = stereo ? GL_TRUE : GL_FALSE; };
  void setSRGBCapable(bool sRGB){ setOptions[GLFW_SRGB_CAPABLE] = sRGB ? GL_TRUE : GL_FALSE; };
  void setUseEmbeddedLibrary(bool embedded){ setOptions[GLFW_CLIENT_API] = embedded ? GLFW_OPENGL_ES_API : GLFW_OPENGL_API; };
 
  void setColorBits(int red, int green, int blue, int alpha){
    setOptions[GLFW_RED_BITS] = red;
    setOptions[GLFW_GREEN_BITS] = green;
    setOptions[GLFW_BLUE_BITS] = blue;
    setOptions[GLFW_ALPHA_BITS] = alpha;
  };
  void setAccumBits(int red, int green, int blue, int alpha){
    setOptions[GLFW_ACCUM_RED_BITS] = red;
    setOptions[GLFW_ACCUM_GREEN_BITS] = green;
    setOptions[GLFW_ACCUM_BLUE_BITS] = blue;
    setOptions[GLFW_ACCUM_ALPHA_BITS] = alpha;
  };
 void setContextApiVersion(int major, int minor){
    setOptions[GLFW_CONTEXT_VERSION_MAJOR] = major;
    setOptions[GLFW_CONTEXT_VERSION_MINOR] = minor;
  };

  //TODO make an opengl profile method
  //TODO make a context robustness method

  void applyOptions(){
    for(std::map<int,int>::iterator it = setOptions.begin(); it != setOptions.end(); ++it){
      glfwWindowHint(it->first, it->second);
    }
  }
};



class DWindow{
  GLFWwindow* windowHandle;
public:
  void* userPointer;
  DWindow(){
    windowHandle = NULL;
    userPointer = NULL;
  }
  operator GLFWwindow*() const{
    return this->windowHandle;
  };

  bool createWindow(int width, int height, const char* title){
    windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
    return windowHandle != NULL;
  };

  bool createWindow(int width, int height, const char* title, const DMonitor& monitor){
    windowHandle = glfwCreateWindow(width, height, title, monitor, NULL);
    return windowHandle != NULL;
  };

  bool createWindow(int width, int height, const char* title, const DWindow& share){
    windowHandle = glfwCreateWindow(width, height, title, NULL, share);
    return windowHandle != NULL;
  };

  bool createWindow(int width, int height, const char* title, const DMonitor& monitor, const DWindow& share){
    windowHandle = glfwCreateWindow(width, height, title, monitor, share);
    return windowHandle != NULL;
  };

};


}}};

#endif
