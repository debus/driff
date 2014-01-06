#ifndef _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55
#define _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55

std::map<int, void*> functionMap;

typedef std::map<int, void*>::iterator fmap_it;


public:
typedef void(*DWindowKeyFun)(DWindow*,KeyboardKey,ScanCode,ButtonAction,ModifierKeys);
typedef void(*DWindowMouseButtonFun)(DWindow*,MouseButton,ButtonAction,ModifierKeys);
typedef void(*DWindowCursorPosFun)(DWindow*,double,double);
typedef void(*DWindowCloseFun)(DWindow*);
typedef void(*DWindowRefreshFun)(DWindow*);
typedef void(*DWindowFocusFun)(DWindow*);
typedef void(*DWindowRectFun)(DWindow*,int,WindowRect);
protected: 
typedef void*(*glfwSetFun)(GLFWwindow*,void*);

inline void* __setCallbackFunction(void* newFunction, void* intermed, int cfID, glfwSetFun setFun){
  std::map<int,void*>::iterator old = functionMap.find(cfID);
  void* ret = NULL;
  if(old != functionMap.end()){
    ret = old->second;
  } if(newFunction != NULL){
    functionMap[cfID] = newFunction;
    setFun(*this,intermed);
  }else{
    functionMap.erase(cfID);
    setFun(*this,NULL);
  } return ret;
};

static void __MouseButtonFunction (GLFWwindow* window,int button,int action,int mods){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_MOUSE_BUTTON_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowMouseButtonFun)f->second)(dwindow,button,action,mods);
  } 
};

static void __KeyFunction (GLFWwindow* window,int key, int scancode, int action, int mods){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_KEY_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowKeyFun)f->second)(dwindow,key,scancode,action,mods);
  }
};

static void __CursorPosFunction (GLFWwindow* window,double x, double y){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_CURSOR_POS_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowCursorPosFun)f->second)(dwindow,x,y);
  }
};

static void __CloseFunction(GLFWwindow* window){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_CLOSE_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowCloseFun)f->second)(dwindow);
  } 
};

static void __RefreshFunction(GLFWwindow* window){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_REFRESH_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowRefreshFun)f->second)(dwindow);
  } 
};

static void __FocusFunction(GLFWwindow* window){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_FOCUS_CALLBACK);
  if(f != dwindow->functionMap.end()){
    ((DWindowRefreshFun)f->second)(dwindow);
  } 
};

static void __WindowPosFunction(GLFWwindow* window, int x, int y){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_POS_CALLBACK);
  if(f != dwindow->functionMap.end()){
    WindowRect rect;
    rect.x = x;
    rect.y = y;
    ((DWindowRectFun)f->second)(dwindow,DGLFW_WINDOW_POSITION_CHANGED,rect);
  } 
};

static void __WindowSizeFunction(GLFWwindow* window, int width, int height){
  window::DWindow* dwindow = NULL;
  window::DWindow::__DWindowFromGLFWwindow(window,&dwindow);
  fmap_it f = dwindow->functionMap.find(DGLFW_WINDOW_SIZE_CALLBACK);
  if(f != dwindow->functionMap.end()){
    WindowRect rect;
    rect.width = width;
    rect.height = height;
    ((DWindowRectFun)f->second)(dwindow,DGLFW_WINDOW_SIZE_CHANGED,rect);
  } 
};


public:

DWindowMouseButtonFun setMouseButtonCallback( DWindowMouseButtonFun cbFun ) {
  return (DWindowMouseButtonFun)__setCallbackFunction((void*)cbFun,(void*)__MouseButtonFunction,DGLFW_WINDOW_MOUSE_BUTTON_CALLBACK,(glfwSetFun)glfwSetMouseButtonCallback);
};

DWindowKeyFun setKeyCallback( DWindowKeyFun cbFun ) {
  return (DWindowKeyFun)__setCallbackFunction((void*)cbFun,(void*)__KeyFunction,DGLFW_WINDOW_KEY_CALLBACK,(glfwSetFun)glfwSetKeyCallback);
};

DWindowCursorPosFun setCursorPosCallback( DWindowCursorPosFun cbFun ) {
  return (DWindowCursorPosFun)__setCallbackFunction((void*)cbFun,(void*)__CursorPosFunction,DGLFW_WINDOW_CURSOR_POS_CALLBACK,(glfwSetFun)glfwSetCursorPosCallback);
};

DWindowCloseFun setCloseCallback(DWindowCloseFun cbFun){
  return (DWindowCloseFun)__setCallbackFunction((void*)cbFun,(void*)__CloseFunction,DGLFW_WINDOW_CLOSE_CALLBACK,(glfwSetFun)glfwSetWindowCloseCallback);
};

DWindowRefreshFun setRefreshCallback(DWindowRefreshFun cbFun){
  return (DWindowRefreshFun)__setCallbackFunction((void*)cbFun,(void*)__RefreshFunction,DGLFW_WINDOW_REFRESH_CALLBACK,(glfwSetFun)glfwSetWindowRefreshCallback);
};

DWindowFocusFun setFocusCallback(DWindowFocusFun cbFun){
  return (DWindowFocusFun)__setCallbackFunction((void*)cbFun,(void*)__FocusFunction,DGLFW_WINDOW_FOCUS_CALLBACK,(glfwSetFun)glfwSetWindowFocusCallback);
};

DWindowRectFun setRectChangeCallback(DWindowRectFun cbFun){
  __setCallbackFunction((void*)cbFun,(void*)__WindowPosFunction,DGLFW_WINDOW_POS_CALLBACK,(glfwSetFun)glfwSetWindowPosCallback);
  return (DWindowRectFun)__setCallbackFunction((void*)cbFun,(void*)__WindowSizeFunction,DGLFW_WINDOW_SIZE_CALLBACK,(glfwSetFun)glfwSetWindowSizeCallback);
};
#endif // _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55


