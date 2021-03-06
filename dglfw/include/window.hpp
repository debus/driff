#ifndef DEBUS_H_WINDOW_H_SUBED
#define DEBUS_H_WINDOW_H_SUBED
#include <string.h> 
#include <GL/glew.h>
#include "forward_declare.hpp"
#include "monitor.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <map>

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

    protected:
    void __setUserPointer(){
      glfwSetWindowUserPointer(windowHandle, (void*)this);
    };

    bool __setWindowHandle(GLFWwindow* ptr){
      windowHandle = ptr;
      if(windowHandle == NULL)
        return false;

      __setUserPointer();
      return true;
    }

    static void __DWindowFromGLFWwindow(GLFWwindow* handle, DWindow** ptr){
      if(ptr == NULL || handle == NULL){ return; }
      *ptr =  (DWindow*)glfwGetWindowUserPointer(handle);
    };
    public:
#include "window_callbacks.hpp"
    public:
    void* userPointer;
    DWindow(){
      windowHandle = NULL;
      userPointer = NULL;
    }

    DWindow(GLFWwindow* window){
      __setWindowHandle(window);
    };

    ~DWindow(){
      glfwDestroyWindow(this->windowHandle);
      this->windowHandle = NULL;
    };

    operator GLFWwindow*() const{
      return this->windowHandle;
    };

    bool createWindow(int width, int height, const char* title){
      return __setWindowHandle(glfwCreateWindow(width, height, title, NULL, NULL));
    };

    bool createWindow(int width, int height, const char* title, const DMonitor& monitor){
      return __setWindowHandle(glfwCreateWindow(width, height, title, (GLFWmonitor*)monitor, NULL));
    };

    bool createWindow(int width, int height, const char* title, const DWindow& share){
      return __setWindowHandle(glfwCreateWindow(width, height, title, NULL, (GLFWwindow*)share));
    };

    bool createWindow(int width, int height, const char* title, const DMonitor& monitor, const DWindow& share){
      return __setWindowHandle(glfwCreateWindow(width, height, title, (GLFWmonitor*)monitor, (GLFWwindow*)share));
    };
    
    void setWindowShouldClose(bool should_close){
      glfwSetWindowShouldClose((GLFWwindow*)*this,(int)should_close);
    };
   
    DMonitor getWindowMonitor(){
      glfwGetWindowMonitor(this->windowHandle);
    };

    bool windowShouldClose(){
      return (bool)glfwWindowShouldClose((GLFWwindow*)*this);
    };

    void makeContextCurrent(){
      glfwMakeContextCurrent(this->windowHandle);
    };
    
    void swapBuffers(){
      glfwSwapBuffers(this->windowHandle);
    };

    void restoreWindow(){
      glfwRestoreWindow(this->windowHandle);
    };  
    
    void showWindow(){
      glfwShowWindow(this->windowHandle);
    };

    void hideWindow(){
      glfwHideWindow(this->windowHandle);
    };

    void getWindowRect(WindowRect* rect){
      if(rect != NULL){
        glfwGetWindowPos(this->windowHandle, &rect->x, &rect->y);
        glfwGetWindowSize(this->windowHandle, &rect->width, &rect->height);
      }
    };

    void setWindowRect(const WindowRect* rect){
      if(rect != NULL){
        glfwSetWindowPos(this->windowHandle, rect->x, rect->y);
        glfwSetWindowSize(this->windowHandle, rect->width, rect->height);
      }
    };

    void getWinInfo(DWinInfo* info){
      if(info != NULL){
        getWindowRect(&info->client_area);
        glfwGetFramebufferSize(this->windowHandle, &info->framebuffer_width, &info->framebuffer_height);
      }
    };

    DWinInfo getWinInfo(){
      DWinInfo ret;
      getWindowRect(&ret.client_area);
      glfwGetFramebufferSize(this->windowHandle, &ret.framebuffer_width, &ret.framebuffer_height);
      return ret;
    }

    static DWindow getCurrentContext(){
      return DWindow(glfwGetCurrentContext());
    };

  };


}}};


#endif
