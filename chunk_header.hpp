/*
 * chunkbase.hpp
 *
 *  Created on: Dec 11, 2013
 *      Author: phil
 */

#ifndef CHUNKBASE_HPP_
#define CHUNKBASE_HPP_

namespace debus{
namespace riff{

struct chunk_header_t{
	typedef unsigned int id_type;

	id_type ckID;
	unsigned int ckSize;

	static const unsigned int written_size = (sizeof(ckID) + sizeof(ckSize));
};

};
};


#endif /* CHUNKBASE_HPP_ */
