#ifndef OPENP2P_STRINGSTREAM_HPP
#define OPENP2P_STRINGSTREAM_HPP

#include <stdint.h>
#include <cstddef>
#include <string>

#include <OpenP2P/Stream.hpp>

namespace OpenP2P{

	class StringIStream: public IStream{
		public:
			StringIStream(const std::string&);

			Future<Block> readSome();

		private:
			const std::string& string_;
			std::size_t pos_;

	};

}

#endif
