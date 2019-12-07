


#include <SDL.h>
#include "SDLMicrophone.h"


namespace lime {
	int dev;

	void Microphone::open () {
		SDL_AudioSpec want, have;
		SDL_AudioDeviceID dev;
		SDL_memset(&want,0,sizeof(want));
		want.freq = 48000;
		want.format = AUDIO_F32SYS;
		want.channels = 1;
		want.samples = 4096;
		//want.callback = callback;
		dev = SDL_OpenAudioDevice(NULL,SDL_TRUE,&want,&have,0/*SDL_AUDIO_ALLOW_FORMAT_CHANGE*/);
		//chec
		if (dev == 0)
		{
			SDL_Log("Failed to open audio: %s", SDL_GetError());
		}else{
			if (have.format != want.format)
			{
				SDL_Log("We didn't get the audio format we wanted");
			}
		}
	}
	/*void SDLMicrophone::callback(void* userdata, uint8_t* stream,int len) {

	}*/
	void Microphone::pause(int index) {
		SDL_PauseAudioDevice(dev,index);
	}
	void Microphone::close() {
		SDL_CloseAudioDevice(dev);
	}
	void Microphone::lock() {
		SDL_LockAudioDevice(dev);
	}
	void Microphone::unlock() {
		SDL_UnlockAudioDevice(dev);
	}
};