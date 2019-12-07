#include <system/CFFI.h>
#include <ui/Microphone.h>
#include <backend/sdl/SDLMicrophone.h>


namespace lime {
		void Microphone::open() {
			//SDLMicrophone::open();
		}
		void Microphone::close() {
			SDLMicrophone::close();
		}
		void Microphone::pause(int index) {
			SDLMicrophone::pause(index);
		}
		void Microphone::unlock() {
			SDLMicrophone::unlock();
		}
		void Microphone::lock() {
			SDLMicrophone::lock();
		}
};