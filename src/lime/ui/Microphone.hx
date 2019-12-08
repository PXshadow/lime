package lime.ui;

import lime._internal.backend.native.NativeCFFI;
import haxe.io.UInt8Array;
import lime.app.Event;

#if !lime_debug
@:fileXml('tags="haxe,release"')
@:noDebug
#end
@:access(lime._internal.backend.native.NativeCFFI)
class Microphone
{
	//import lime.utils.UInt8Array;
	public var onCallback = new Event<UInt8Array->Float->Void>();

	@:noCompletion public static function open():Void
	{
		#if (lime_cffi && !macro)
		NativeCFFI.lime_microphone_open();
		#end
	}

	@:noCompletion public static function close():Void
	{
		#if (lime_cffi && !macro)
		NativeCFFI.lime_microphone_close();
		#end
	}
	@:noCompletion public static function pause(int:Int):Void
	{
		#if (lime_cffi && !macro)
		//NativeCFFI.lime_microphone_pause(int);
		NativeCFFI.lime_microphone_pause(int);
		#end
	}
}
