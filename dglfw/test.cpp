#include <stdio.h>
#include <stdlib.h>
#include "dglfw.hpp"

using namespace debus::dglfw;

void printMonitorInfo();
void error_function(error_handling::ERROR_CODE code, const char* message);
int main(int argc, char** argv){
  if(!dglfwInit()){
    fprintf(stderr, "Failed to initialize DWindow\n");
    return 1;
  } 

  error_handling::setErrorCallback(error_function);

  printMonitorInfo();

  window::DWindowOptions opts;
  opts.applyOptions();
  window::DWindow window;
  if(!window.createWindow(800,600,"TEST WINDOW")){
    fprintf(stderr, "Failed to create window\n");
    dglfwTerminate();
    return -1;
  }
  getchar();
  return 0;
}

void printMonitorInfo(){
  printf("Monitor information:\n");
  std::vector<DMonitor> monitors = DMonitor::getMonitors();
  DMonitor primary = DMonitor::getPrimaryMonitor();
  for(std::vector<DMonitor>::iterator it = monitors.begin(); it != monitors.end(); ++it){
    int a,b;
    printf("\t%s:",it->getName());
    if(primary == *it){
      printf(" (Primary)");
    }
    printf("\n");
    it->getPosition(&a,&b);
    printf("\t\tPosition:\t%d,%d\n",a,b);
    it->getPhysicalSize(&a,&b);
    printf("\t\tPhysical Size:\t%dX%d (mm)\n",a,b);
    const DVideoMode* current = it->getVideoMode();
    std::vector<DVideoMode> modes = it->getVideoModes();
    printf("\t\tVideo Modes: (widthXheight,refresh rate, red green blue bits)\n");
    printf("\t\t\tCurrent: %dX%d,%dHz,%d,%d,%d\n", current->width,current->height,current->refreshRate,current->redBits,current->greenBits,current->blueBits);
    printf("\t\t\tAll: \n");
    for(std::vector<DVideoMode>::iterator mode = modes.begin(); mode != modes.end(); ++mode){
      printf("\t\t\t%dX%d,%dHz,%d,%d,%d",mode->width,mode->height,mode->refreshRate,mode->redBits,mode->greenBits,mode->blueBits);
      if(*mode == *current){
        printf(" (current)");
      }
      printf("\n");
    }
    printf("\t\tGammaSize: %d\n", it->getGammaRamp()->size);
  }
}

void error_function(error_handling::ERROR_CODE code, const char* message){
  fprintf(stderr, "Error (%d) '%s'\n", code, message);
};
