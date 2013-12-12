/*
 * serializable.hpp
 *
 *  Created on: Dec 11, 2013
 *      Author: phil
 */

#ifndef SERIALIZABLE_HPP_
#define SERIALIZABLE_HPP_

#include <iostream>

namespace debus{namespace riff{namespace serialization{

class serializable_t{
public:
	virtual std::istream& read(std::istream& is) = 0;
	virtual std::ostream& write(std::ostream& os) const = 0;
	virtual ~serializable_t(){};
};

std::istream& operator>=(std::istream& is, serializable_t& ser){
	return ser.read(is);
}

template<typename T>
std::istream& operator>=(std::istream& is, T& val){
	return is.read((char*)&val, sizeof(T));
}

std::ostream& operator<=(std::ostream& os, serializable_t& ser){
	return ser.write(os);
}

template<typename T>
std::ostream& operator<=(std::ostream& os, T& val){
	return os.write((const char*)&val, sizeof(T));
}
}}};


#endif /* SERIALIZABLE_HPP_ */
