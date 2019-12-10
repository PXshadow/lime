


#include <SDL.h>
#include "SDLMicrophone.h"


namespace lime {

	int dev;
	void audioRecordingCallback( void* userdata, Uint8* stream, int len ) {

	}
	void Microphone::open () {
		SDL_Log("open microphone");

		SDL_AudioSpec want, have;
		SDL_AudioDeviceID dev;
		SDL_memset(&want,0,sizeof(want));
		want.freq = 48000;
		want.format = AUDIO_F32SYS;
		want.channels = 1;
		want.samples = 4096;
		//want.callback = NULL;
		want.callback = audioRecordingCallback;
		dev = SDL_OpenAudioDevice(NULL,SDL_TRUE,&want,&have,0);
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
	/*Uint8* Microphone::get() {
		return buffer;
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