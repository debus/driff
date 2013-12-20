#ifndef DEBUS_H_GAS_H_SUBED
#define DEBUS_H_GAS_H_SUBED

namespace debus{namespace phys{

//PV = nRT

  template<typename T>
  T pressure(T volume, T moles, T R, T temp){ return (moles*R*temp)/volume; }

  template<typename T>
  T volume(T pressure, T moles, T R, T temp){ return (moles*R*temp)/pressure; }

  template<typename T>
  T moles(T pressure, T volume, T R, T temp){ return (pressure*volume)/(R*temp); }

  template<typename T>
  T temperature(T pressure, T volume, T moles, T R){ return (pressure*volume)/(R*moles); }

}};

#endif
