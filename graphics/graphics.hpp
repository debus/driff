#ifndef DEBUS_H_GRAPHICS_H_SUBED
#define DEBUS_H_GRAPHICS_H_SUBED
#include <string.h> 
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

namespace debus{namespace graphics{

struct window_hints_t{
  unsigned char refresh_rate;
  unsigned char accum_bits_red, accum_bits_green, accum_bits_blue, accum_bits_alpha;
  unsigned char aux_buffers;
  bool stereo;
  bool no_resize_window;
  unsigned char fsaa_samples;
  bool forward_compat;
  bool debug_context;
  unsigned int profile;
  unsigned char opengl_version_major;
  unsigned char opengl_version_minor;

  static void make_default(window_hints_t* ptr){
    if(ptr != NULL){
      memset(ptr,0, sizeof(window_hints_t));
      ptr->opengl_version_major = 1;
      ptr->opengl_version_minor = 1;
    }
  };
};

const unsigned int WINDOW_HINTS_DEFS[14][2] = {
  {GLFW_REFRESH_RATE, (unsigned int)&((window_hints_t*)NULL)->refresh_rate},
  {GLFW_ACCUM_RED_BITS, (unsigned int)&((window_hints_t*)NULL)->accum_bits_red},
  {GLFW_ACCUM_GREEN_BITS, (unsigned int)&((window_hints_t*)NULL)->accum_bits_green},
  {GLFW_ACCUM_BLUE_BITS, (unsigned int)&((window_hints_t*)NULL)->accum_bits_blue},
  {GLFW_ACCUM_ALPHA_BITS, (unsigned int)&((window_hints_t*)NULL)->accum_bits_alpha},
  {GLFW_AUX_BUFFERS, (unsigned int)&((window_hints_t*)NULL)->aux_buffers},
  {GLFW_STEREO, (unsigned int)&((window_hints_t*)NULL)->stereo},
  {GLFW_WINDOW_NO_RESIZE, (unsigned int)&((window_hints_t*)NULL)->no_resize_window},
  {GLFW_FSAA_SAMPLES, (unsigned int)&((window_hints_t*)NULL)->fsaa_samples},
  {GLFW_OPENGL_VERSION_MAJOR, (unsigned int)&((window_hints_t*)NULL)->opengl_version_major},
  {GLFW_OPENGL_VERSION_MINOR, (unsigned int)&((window_hints_t*)NULL)->opengl_version_minor},
  {GLFW_OPENGL_FORWARD_COMPAT, (unsigned int)&((window_hints_t*)NULL)->forward_compat},
  {GLFW_OPENGL_DEBUG_CONTEXT, (unsigned int)&((window_hints_t*)NULL)->debug_context},
  {GLFW_OPENGL_PROFILE, (unsigned int)&((window_hints_t*)NULL)->profile}
};


struct window_options_t{
  window_hints_t hints;
  unsigned int width, height;
  unsigned char redbits, greenbits, bluebits; 
  unsigned char alphabits, depthbits, stencilbits;
  bool fullscreen;

  window_options_t(){
    make_default(this);
  }

  static void make_default(window_options_t* ptr){
    if(ptr != NULL){
      window_hints_t::make_default(&ptr->hints);
      memset(&ptr->width, 0, ((unsigned int)&ptr->fullscreen - (unsigned int)&ptr->width)+sizeof(window_options_t::fullscreen));
    }
  };
};

void __prep_window_hints(const window_hints_t* ptr){
  if(ptr != NULL){
    for(int i = 0; i < sizeof(WINDOW_HINTS_DEFS)/8; ++i){
      unsigned int v = *(((unsigned char*)ptr)+WINDOW_HINTS_DEFS[i][1]);
      fprintf(stdout, "i=%u a=%u v=%u\n",i,WINDOW_HINTS_DEFS[i][0],v);
      glfwOpenWindowHint(WINDOW_HINTS_DEFS[i][0], v);
    }
  }
}

int open_window(const window_options_t* ptr){
  if(ptr != NULL){
    __prep_window_hints(&ptr->hints);
    int mode = GLFW_WINDOW;
    if(ptr->fullscreen){
      mode = GLFW_FULLSCREEN;
    }

    return glfwOpenWindow(ptr->width, ptr->height, ptr->redbits, ptr->greenbits, ptr->bluebits, ptr->alphabits, ptr->depthbits, ptr->stencilbits, mode);
  }else{
    return 0;
  }
}

}};

#endif
