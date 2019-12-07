


#include <SDL.h>
#include <map>
#include <stdint.h>


namespace lime {


	class SDLMicrophone {

		public:
			static void open ();
			static void close ();
			static void pause (int index);
			static void callback (void* userdata, uint8_t* stream,int len);
			static void lock ();
			static void unlock ();
	};
}