#ifndef _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55
#define _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55

std::map<int, void*> functionMap;
typedef std::map<int, void*>::iterator fmap_it;
#define GET_DWINDOW(dwin,win) window::DWindow* dwin = NULL; window::DWindow::__DWindowFromGLFWwindow(win,&dwin);
public:

#define CALLBACK_FUNCTION_TYPE(fun,params) typedef void(*fun)params;

#define CALLBACK_FUNCTIONS(type,name,fid,glfwf,staticfunction) type name( type cbFun ) { \
  std::map<int,void*>::iterator old = functionMap.find(fid);\
  type ret = NULL;\
  if(old != functionMap.end()){\
    ret = (type)old->second;\
  }\
  if(cbFun != NULL){\
    functionMap[fid] = (void*)cbFun;\
    glfwf(*this,staticfunction);\
  }else{\
    functionMap.erase(fid);\
    glfwf(*this,NULL);\
  }\
  return ret;\
};

#define INTERMEDIATE_STATIC(fname,iparams,fpt,passing_params,cfid) protected: \
  static void fname iparams{\
    GET_DWINDOW(dwindow,window);\
    fmap_it f = dwindow->functionMap.find(cfid);\
    if(f != dwindow->functionMap.end()){\
      ((fpt)f->second)passing_params;\
    }\
  };\
    public: 

#define CALLBACK_COMBO(fpt,fpparams,setter,cfid,glfwf_setter,static_intermediate,iparams,passing_params) \
      INTERMEDIATE_STATIC(static_intermediate,iparams,fpt,passing_params,cfid);\
    CALLBACK_FUNCTION_TYPE(fpt,fpparams);\
    CALLBACK_FUNCTIONS(fpt,setter,cfid,glfwf_setter,static_intermediate);

    CALLBACK_COMBO(DWindowMouseButtonFun,(DWindow*,MouseButton,ButtonAction,ModifierKeys),setMouseButtonCallback,DGLFW_WINDOW_MOUSE_BUTTON_CALLBACK,glfwSetMouseButtonCallback,__MouseButtonFunction, (GLFWwindow* window,int button,int action,int mods), (dwindow,button,action,mods));

    CALLBACK_COMBO(DWindowKeyFun, (DWindow*,KeyboardKey,ScanCode,ButtonAction,ModifierKeys), setKeyCallback, DGLFW_WINDOW_KEY_CALLBACK, glfwSetKeyCallback,__KeyFunction,(GLFWwindow* window,int key, int scancode, int action, int mods),(dwindow,key,scancode,action,mods));

    CALLBACK_COMBO(DWindowCursorPosFun, (DWindow*,double,double), setCursorPosCallback, DGLFW_WINDOW_CURSOR_POS_CALLBACK, glfwSetCursorPosCallback,__CursorPosFunction,(GLFWwindow* window,double x, double y),(dwindow,x,y));

#endif // _INCLUDE_GUARD_C9A55B71_E5F3_44E3_8AE3_F41C67960D55

