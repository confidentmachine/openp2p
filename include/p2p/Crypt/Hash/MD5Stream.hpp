#ifndef P2P_CRYPT_HASH_MD5STREAM_HPP
#define P2P_CRYPT_HASH_MD5STREAM_HPP

#include <stdint.h>

#include <memory>

#include <p2p/Transport.hpp>
#include <p2p/Transport/Stream.hpp>

namespace p2p {

	namespace Crypt {
	
		namespace Hash {
		
			/**
			 * \brief MD5 Stream
			 * 
			 * Note that the MD5 algorithm is now considered
			 * unsuitable for security purposes; this should
			 * be used for applications where hash security
			 * is not required.
			 */
			class MD5Stream: public OStream {
				public:
					MD5Stream();
					~MD5Stream();
					
					bool isValid() const;
					
					Event::Source eventSource() const;
					
					size_t write(const uint8_t* data, size_t size);
					
					Buffer calculateDigest();
					
				private:
					// Non-copyable.
					MD5Stream(const MD5Stream&) = delete;
					MD5Stream& operator=(MD5Stream) = delete;
					
					std::unique_ptr<struct MD5StreamImpl> impl_;
					
			};
			
		}
		
	}
	
}

#endif
