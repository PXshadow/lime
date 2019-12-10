#ifndef LIME_UI_MICROPHONE_H
#define LIME_UI_MICROPHONE_H


namespace lime {

	struct Microphone {

		public:
		static void open();
		static void close();
		static void pause(int index);
		static void callback();
		static uint8_t get();
		static void lock();
		static void unlock();
	};


}


#endif