#include "JProcess.h"

#using <System.dll>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace JavaRemote {
	public enum class JVals : int {
		VAL_FALSE = 0,
		VAL_TRUE = 1,

		VAL_OK = 0,
		VAL_ERR = -1,
		VAL_EDATCHED = -2,
		VAL_EVERSION = -3,
		VAL_ENOMEM = -4,
		VAL_EEXIST = -5,
		VAL_EINVAL = -6,

		VAL_COMMIT = 1,
		VAL_ABORT = 2,

		VAL_VERSION_1_1 = 0x00010001,
		VAL_VERSION_1_2 = 0x00010002,
		VAL_VERSION_1_4 = 0x00010004,	
		VAL_VERSION_1_6 = 0x00010006,
		VAL_VERSION_1_8 = 0x00010008
	};

	public ref class JValue {
	internal:
		JValue() {}
		virtual jvalue GetJValue() { jvalue v; return v; };
	};

	public ref class JBoolean : public JValue {
	internal:
		jboolean _boolean;
		JBoolean(jboolean inbool) {
			this->_boolean = inbool;
		}
		jvalue GetJValue() override {
			jvalue v;
			v.z = this->_boolean;
			return v;
		}
	public:
		JBoolean(bool inbool) {
			_boolean = inbool ? (int)JVals::VAL_TRUE : (int)JVals::VAL_FALSE;
		}
		bool Value() {
			bool val = _boolean == (int)JVals::VAL_TRUE ? true : false;
			return val;
		}
	};

	public ref class JByte : public JValue {
	internal:
		jbyte _byte;
		jvalue GetJValue() override {
			jvalue v;
			v.b = this->_byte;
			return v;
		}
	public:
		JByte(jbyte inbyte) {
			this->_byte = inbyte;
		}
		jbyte Value() {
			return _byte;
		}
	};

	public ref class JChar : public JValue {
	internal:
		jchar _char;
		jvalue GetJValue() override {
			jvalue v;
			v.c = this->_char;
			return v;
		}
	public:
		JChar(jchar inchar) {
			this->_char = inchar;
		}
		jchar Value() {
			return _char;
		}
	};

	public ref class JShort : public JValue {
	internal:
		jshort _short;
		jvalue GetJValue() override {
			jvalue v;
			v.s = this->_short;
			return v;
		}
	public:
		JShort(jshort inshort) {
			this->_short = inshort;
		}
		jshort Value() {
			return _short;
		}
	};

	public ref class JInt : public JValue {
	internal:
		jint _int;
		jvalue GetJValue() override {
			jvalue v;
			v.i = this->_int;
			return v;
		}
	public:
		JInt(jint inint) {
			this->_int = inint;
		}
		jint Value() {
			return _int;
		}
	};

	public ref class JLong : public JValue {
	internal:
		jlong _long;
		jvalue GetJValue() override {
			jvalue v;
			v.j = this->_long;
			return v;
		}
	public:
		JLong(jlong inlong) {
			this->_long = inlong;
		}
		jlong Value() {
			return _long;
		}
	};

	public ref class JFloat : public JValue {
	internal:
		jfloat _float;
		jvalue GetJValue() override {
			jvalue v;
			v.f = this->_float;
			return v;
		}
	public:
		JFloat(jfloat infloat) {
			this->_float = infloat;
		}
		jfloat Value() {
			return _float;
		}
	};

	public ref class JDouble : public JValue {
	internal:
		jdouble _double;
		jvalue GetJValue() override {
			jvalue v;
			v.d = this->_double;
			return v;
		}
	public:
		JDouble(jdouble indouble) {
			this->_double = indouble;
		}
		jdouble Value() {
			return _double;
		}
	};

	public ref class JObject : public JValue {
	internal:
		jobject _obj = nullptr;
		JObject(jobject inobj) {
			this->_obj = inobj;
		};
		jvalue GetJValue() override {
			jvalue v;
			v.l = this->_obj;
			return v;
		}
	};

	public ref class JThrowable : public JObject {
	internal:
		jthrowable _throwable;
		JThrowable(jthrowable inthrow) : JObject(inthrow) {
			this->_throwable = inthrow;
		}
	};

	public ref class JClass : public JObject {
	internal:
		jclass _class;
		JClass(jclass inclass) : JObject(inclass) {
			this->_class = inclass;
		}
	};

	public ref class JString : public JObject {
	internal:
		jstring _string;
		JString(jstring instring) : JObject(instring) {
			this->_string = instring;
		}
	};

	public ref class JArray : public JObject {
	internal:
		jarray _array;
		JArray(jarray inarray) : JObject(inarray) {
			this->_array = inarray;
		}
	};

	public ref class JBooleanArray : public JArray {
	internal:
		jbooleanArray _booleanArray;
		JBooleanArray(jbooleanArray inarray) : JArray(inarray) {
			this->_booleanArray = inarray;
		}
	};

	public ref class JByteArray : public JArray {
	internal:
		jbyteArray _byteArray;
		JByteArray(jbyteArray inarray) : JArray(inarray) {
			this->_byteArray = inarray;
		}
	};

	public ref class JCharArray : public JArray {
	internal:
		jcharArray _charArray;
		JCharArray(jcharArray inarray) : JArray(inarray) {
			this->_charArray = inarray;
		}
	};

	public ref class JShortArray : public JArray {
	internal:
		jshortArray _shortArray;
		JShortArray(jshortArray inarray) : JArray(inarray) {
			this->_shortArray = inarray;
		}
	};

	public ref class JIntArray : public JArray {
	internal:
		jintArray _intArray;
		JIntArray(jintArray inarray) : JArray(inarray) {
			this->_intArray = inarray;
		}
	};

	public ref class JLongArray : public JArray {
	internal:
		jlongArray _longArray;
		JLongArray(jlongArray inarray) : JArray(inarray) {
			this->_longArray = inarray;
		}
	};

	public ref class JFloatArray : public JArray {
	internal:
		jfloatArray _floatArray;
		JFloatArray(jfloatArray inarray) : JArray(inarray) {
			this->_floatArray = inarray;
		}
	};
	
	public ref class JDoubleArray : public JArray {
	internal:
		jdoubleArray _doubleArray;
		JDoubleArray(jdoubleArray inarray) : JArray(inarray) {
			this->_doubleArray = inarray;
		}
	};

	public ref class JObjectArray : public JArray {
	internal:
		jobjectArray _objectArrary;
		JObjectArray(jobjectArray inarray) : JArray(inarray) {
			this->_objectArrary = inarray;
		}
	};

	public ref class JFieldID {
	internal:
		jfieldID _fieldID = nullptr;
		JFieldID(jfieldID infid) {
			this->_fieldID = infid;
		}
	};

	public ref class JMethodID {
	internal:
		jmethodID _methodId = nullptr;
		JMethodID(jmethodID inmid) {
			this->_methodId = inmid;
		}
	};

	public ref class JProcess {
	public:
		JInt^ GetVersion();
		JClass^ FindClass(String^ name); 
		JMethodID^ FromReflectedMethod(JObject^ method);
		JFieldID^ FromReflectedField(JObject^ field);

		JObject^ ToReflectedMethod(JClass^ cls, JMethodID^ methodID, JBoolean^ isStatic);

		JClass^ GetSuperclass(JClass^ sub);
		JBoolean^ IsAssignableFrom(JClass^ sub, JClass^ sup);

		JObject^ ToReflectedField(JClass^ cls, JFieldID^ fieldID, JBoolean^ isStatic);

		JInt^ Throw(JThrowable^ obj);
		JInt^ ThrowNew(JClass^ clazz, String^ msg);
		JThrowable^ ExceptionOccurred();
		void ExceptionDescribe();
		void ExceptionClear();
		void FatalError(String^ msg);
		JInt^ PushLocalFrame(JInt^ capacity);
		JObject^ PopLocalFrame(JObject^ result);

		JObject^ NewGlobalRef(JObject^ lobj);
		void  DeleteGlobalRef(JObject^ gref);
		void  DeleteLocalRef(JObject^ obj);
		JBoolean^ IsSameObject(JObject^ obj1, JObject^ obj2);
		JObject^ NewLocalRef(JObject^ ref);
		JInt^ EnsureLocalCapacity(JInt^ capacity);

		JObject^ AllocObject(JClass^ clazz);
		JObject^ NewObject(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args);

		JClass^ GetObjectClass(JObject^ obj);
		JBoolean^ IsInstanceOf(JObject^ obj, JClass^ clazz);
		JMethodID^ GetMethodID(JClass^ clazz, String^ name, String^ sig);

		JObject^ CallObjectMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args);

		JBoolean^ CallBooleanMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args);

		JByte^ CallByteMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JChar^ CallCharMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JShort^ CallShortMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JInt^ CallIntMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JLong^ CallLongMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JFloat^ CallFloatMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		JDouble^ CallDoubleMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args);

		void  CallVoidMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args);

		JObject^ CallNonvirtualObjectMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args);

		JBoolean^ CallNonvirtualBooleanMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args);

		JByte^ CallNonvirtualByteMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JChar^ CallNonvirtualCharMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JShort^ CallNonvirtualShortMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JInt^ CallNonvirtualIntMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JLong^ CallNonvirtualLongMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JFloat^ CallNonvirtualFloatMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JDouble^ CallNonvirtualDoubleMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		void  CallNonvirtualVoidMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args);

		JFieldID^ GetFieldID(JClass^ clazz, String^ name, String^ sig);

		JObject^ GetObjectField(JObject^ obj, JFieldID^ fieldID);
		JBoolean^ GetBooleanField(JObject^ obj, JFieldID^ fieldID);
		JByte^ GetByteField(JObject^ obj, JFieldID^ fieldID);
		JChar^ GetCharField(JObject^ obj, JFieldID^ fieldID);
		JShort^ GetShortField(JObject^ obj, JFieldID^ fieldID);
		JInt^ GetIntField(JObject^ obj, JFieldID^ fieldID);
		JLong^ GetLongField(JObject^ obj, JFieldID^ fieldID);
		JFloat^ GetFloatField(JObject^ obj, JFieldID^ fieldID);
		JDouble^ GetDoubleField(JObject^ obj, JFieldID^ fieldID);

		void  SetObjectField(JObject^ obj, JFieldID^ fieldID, JObject^ val);
		void  SetBooleanField(JObject^ obj, JFieldID^ fieldID, JBoolean^ val);
		void  SetByteField(JObject^ obj, JFieldID^ fieldID, JByte^ val);
		void  SetCharField(JObject^ obj, JFieldID^ fieldID, JChar^ val);
		void  SetShortField(JObject^ obj, JFieldID^ fieldID, JShort^ val);
		void  SetIntField(JObject^ obj, JFieldID^ fieldID, JInt^ val);
		void  SetLongField(JObject^ obj, JFieldID^ fieldID, JLong^ val);
		void  SetFloatField(JObject^ obj, JFieldID^ fieldID, JFloat^ val);
		void  SetDoubleField(JObject^ obj, JFieldID^ fieldID, JDouble^ val);

		JMethodID^ GetStaticMethodID(JClass^ clazz, String^ name, String^ sig);

		JObject^ CallStaticObjectMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JBoolean^ CallStaticBooleanMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JByte^ CallStaticByteMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JChar^ CallStaticCharMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JShort^ CallStaticShortMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JInt^ CallStaticIntMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JLong^ CallStaticLongMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JFloat^ CallStaticFloatMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		JDouble^ CallStaticDoubleMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args);

		void  CallStaticVoidMethod(JClass^ cls, JMethodID^ methodID, ... array<JValue^>^ args);

		JFieldID^ GetStaticFieldID(JClass^ clazz, String^ name, String^ sig);
		JObject^ GetStaticObjectField(JClass^ clazz, JFieldID^ fieldID);
		JBoolean^ GetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID);
		JByte^ GetStaticByteField(JClass^ clazz, JFieldID^ fieldID);
		JChar^ GetStaticCharField(JClass^ clazz, JFieldID^ fieldID);
		JShort^ GetStaticShortField(JClass^ clazz, JFieldID^ fieldID);
		JInt^ GetStaticIntField(JClass^ clazz, JFieldID^ fieldID);
		JLong^ GetStaticLongField(JClass^ clazz, JFieldID^ fieldID);
		JFloat^ GetStaticFloatField(JClass^ clazz, JFieldID^ fieldID);
		JDouble^ GetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID);

		void  SetStaticObjectField(JClass^ clazz, JFieldID^ fieldID, JObject^ value);
		void  SetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID, JBoolean^ value);
		void  SetStaticByteField(JClass^ clazz, JFieldID^ fieldID, JByte^ value);
		void  SetStaticCharField(JClass^ clazz, JFieldID^ fieldID, JChar^ value);
		void  SetStaticShortField(JClass^ clazz, JFieldID^ fieldID, JShort^ value);
		void  SetStaticIntField(JClass^ clazz, JFieldID^ fieldID, JInt^ value);
		void  SetStaticLongField(JClass^ clazz, JFieldID^ fieldID, JLong^ value);
		void  SetStaticFloatField(JClass^ clazz, JFieldID^ fieldID, JFloat^ value);
		void  SetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID, JDouble^ value);

		JString^ NewString(String^ unicode);
		JInt^ GetStringLength(JString^ str);
		array<JChar^>^ GetStringChars(JString^ str, [OutAttribute] JBoolean^% isCopy);
		void  ReleaseStringChars(JString^ str, array<JChar^>^ chars);

		JString^ NewStringUTF(String^ utf);
		JInt^ GetStringUTFLength(JString^ str);
		String^  GetStringUTFChars(JString^ str, [OutAttribute] JBoolean^% isCopy);
		void  ReleaseStringUTFChars(JString^ str, String^ chars);


		JInt^ GetArrayLength(JArray^ array);

		JObjectArray^ NewObjectArray(JInt^ len, JClass^ clazz, JObject^ init);
		JObject^ GetObjectArrayElement(JObjectArray^ array, JInt^ index);
		void  SetObjectArrayElement(JObjectArray^ array, JInt^ index, JObject^ val);

		JBooleanArray^ NewBooleanArray(JInt^ len);
		JByteArray^ NewByteArray(JInt^ len);
		JCharArray^ NewCharArray(JInt^ len);
		JShortArray^ NewShortArray(JInt^ len);
		JIntArray^ NewIntArray(JInt^ len);
		JLongArray^ NewLongArray(JInt^ len);
		JFloatArray^ NewFloatArray(JInt^ len);
		JDoubleArray^ NewDoubleArray(JInt^ len);

		array<JBoolean^>^ GetBooleanArrayElements(JBooleanArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JByte^>^  GetByteArrayElements(JByteArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JChar^>^  GetCharArrayElements(JCharArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JShort^>^  GetShortArrayElements(JShortArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JInt^>^ GetIntArrayElements(JIntArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JLong^>^ GetLongArrayElements(JLongArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JFloat^>^  GetFloatArrayElements(JFloatArray^ aarray, [OutAttribute] JBoolean^% isCopy);
		array<JDouble^>^ GetDoubleArrayElements(JDoubleArray^ aarray, [OutAttribute] JBoolean^% isCopy);

		void  ReleaseBooleanArrayElements(JBooleanArray^ aarray, array<JBoolean^>^ elems, JInt^ mode);
		void  ReleaseByteArrayElements(JByteArray^ aarray, array<JByte^>^ elems, JInt^ mode);
		void  ReleaseCharArrayElements(JCharArray^ aarray, array<JChar^>^ elems, JInt^ mode);
		void  ReleaseShortArrayElements(JShortArray^ aarray, array<JShort^>^ elems, JInt^ mode);
		void  ReleaseIntArrayElements(JIntArray^ aarray, array<JInt^>^ elems, JInt^ mode);
		void  ReleaseLongArrayElements(JLongArray^ aarray, array<JLong^>^ elems, JInt^ mode);
		void  ReleaseFloatArrayElements(JFloatArray^ aarray, array<JFloat^>^ elems, JInt^ mode);
		void  ReleaseDoubleArrayElements(JDoubleArray^ aarray, array<JDouble^>^ elems, JInt^ mode);

		void  GetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, [OutAttribute] array<JBoolean^>^% buf);
		void  GetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JByte^>^% buf);
		void  GetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf);
		void  GetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JShort^>^% buf);
		void  GetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JInt^>^% buf);
		void  GetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JLong^>^% buf);
		void  GetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JFloat^>^% buf);
		void  GetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JDouble^>^% buf);

		void  SetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, array<JBoolean^>^ buf);
		void  SetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, array<JByte^>^ buf);
		void  SetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, array<JChar^>^ buf);
		void  SetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, array<JShort^>^ buf);
		void  SetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, array<JInt^>^ buf);
		void  SetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, array<JLong^>^ buf);
		void  SetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, array<JFloat^>^ buf);
		void  SetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, array<JDouble^>^ buf);

		void  GetStringRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf);
		void  GetStringUTFRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] String^% buf);

		/*void *  GetPrimitiveArrayCritical(JArray^ array, [OutAttribute] JBoolean^% isCopy);
		void  ReleasePrimitiveArrayCritical(JArray^ array, void *carray, JInt^ mode);

		const array<JChar^>^ GetStringCritical(JString^ string, [OutAttribute] JBoolean^% isCopy);
		void  ReleaseStringCritical(JString^ string, String^ cstring);*/

		JBoolean^ ExceptionCheck();

		/*JObject^ NewDirectByteBuffer(JNIEnv* env, void* address, JLong^ capacity);
		void*  GetDirectBufferAddress(JNIEnv* env, JObject^ buf);
		JLong^ GetDirectBufferCapacity(JNIEnv* env, JObject^ buf);*/

		IntPtr GetVMPointer();
		IntPtr GetENVPointer();
		static bool Attach(Process^ p, [OutAttribute] JProcess^% jp);
	protected:
		!JProcess() {
			delete _jni;
		}
	private:
		JavaRemoteNative::JProcess* _jni;
		JProcess(int processID) : _jni(new JavaRemoteNative::JProcess(processID)) {};
		~JProcess() {
			delete _jni;
		}
	};
}