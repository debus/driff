#ifndef _INCLUDE_GUARD_49144D1F_D955_407D_AECD_9437AFDD6B4B
#define _INCLUDE_GUARD_49144D1F_D955_407D_AECD_9437AFDD6B4B
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

namespace debus{namespace dglfw{

typedef GLFWvidmode DVideoMode;
typedef GLFWgammaramp DGammaRamp;

class DMonitor{
  GLFWmonitor* monitor;
public:
  DMonitor(){
    monitor = NULL;
  };

  DMonitor(GLFWmonitor* monitor){
    this->monitor = monitor;
  };
  
  operator GLFWmonitor*() const{
    return this->monitor;
  };

  const DVideoMode* getVideoMode(){
    return glfwGetVideoMode(this->monitor);
  };

  const char* getName(){
    return glfwGetMonitorName(this->monitor);
  };

  void getPosition(int* x, int* y){
    glfwGetMonitorPos(this->monitor,x,y);
  };

  void getPhysicalSize(int* width, int* height){
    glfwGetMonitorPhysicalSize(this->monitor,width,height);
  }

  std::vector<const DVideoMode*> getVideoModes(){
    std::vector<const DVideoMode*> list;
    int end = 0;
    const DVideoMode* modes = glfwGetVideoModes(this->monitor, &end);
    if(end == 0 || modes == NULL){
      return list;
    }
    end *= sizeof(modes);
    end += (int)modes; 
    for(; modes < (DVideoMode*)end; ++modes){
      list.push_back(modes);
    }
    return list;
  };


  static std::vector<DMonitor> getMonitors(){
    std::vector<DMonitor> list;
    int end = 0;
    GLFWmonitor** arr = glfwGetMonitors(&end);
    if(end == 0 || arr == NULL){
      return list;
    }
    end *= sizeof(arr);
    end += (int)arr;
    for(; arr < (GLFWmonitor**)end; ++arr){
      list.push_back(DMonitor(*arr));
    }
    return list;
  };
  
  static DMonitor getPrimaryMonitor(){
    return DMonitor(glfwGetPrimaryMonitor());
  };
};

}};

#endif // _INCLUDE_GUARD_49144D1F_D955_407D_AECD_9437AFDD6B4B

