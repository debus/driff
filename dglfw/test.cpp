#include <stdio.h>
#include <stdlib.h>
#include "include/dglfw.hpp"

using namespace debus::dglfw;

void printMonitorInfo();
void error_function(error_handling::ERROR_CODE code, const char* message);
void mouse_callback(window::DWindow*,MouseButton,ButtonAction,ModifierKeys);
void key_callback(window::DWindow*,KeyboardKey,ScanCode,ButtonAction,ModifierKeys);
void cursor_pos_callback(window::DWindow*,double,double);
double cx = 0.0;
double cy = 0.0;
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
  glfwMakeContextCurrent((GLFWwindow*)window);
  window.setMouseButtonCallback(mouse_callback);
  window.setKeyCallback(key_callback);
  window.setCursorPosCallback(cursor_pos_callback);
  double lastTime = glfwGetTime();
  int nbFrames = 0;
  while(!window.windowShouldClose()){
    float ratio;
    int width, height;
    double time = glfwGetTime();
    glfwGetFramebufferSize((GLFWwindow*)window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) time * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(cx/width, cy/height, 0.f);
    glEnd();
    glfwSwapBuffers((GLFWwindow*)window);
    glfwPollEvents();
    ++nbFrames;
    time = glfwGetTime();
    if((time - lastTime) >= 10){
      printf("%f fps\n",double(nbFrames)/(time-lastTime));
      nbFrames = 0;
      lastTime = time;
    }
  }
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


void mouse_callback(window::DWindow* window,MouseButton button,ButtonAction action,ModifierKeys mods){
  printf("Mouse pressed: %d,%d,%d\n",button,action,mods);
}

void key_callback(window::DWindow* window, KeyboardKey key, ScanCode scancode, ButtonAction action, ModifierKeys mods){
  if(key == DGLFW_KEY_ESCAPE){
    window->setWindowShouldClose(true);
  }
  printf("Key pressed: %d,%d,%d,%d\n",key,scancode,action,mods);
}

void cursor_pos_callback(window::DWindow*,double x,double y){
  printf("Cursor pos: %f,%f\n",x,y);
  cx = x;
  cy = y;
}
