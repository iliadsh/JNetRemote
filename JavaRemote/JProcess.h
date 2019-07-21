#pragma once

#include <src/BlackBone/Process/Process.h>
#include <jni.h>

namespace JavaRemoteNative {
	class JProcess {
	public:
		JProcess(DWORD processID);
		~JProcess() = default;

		jint GetVersion();
		jclass FindClass(const char* name);
		jmethodID FromReflectedMethod(jobject method);
		jfieldID FromReflectedField(jobject field);

		jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic);

		jclass GetSuperclass(jclass sub);
		jboolean IsAssignableFrom(jclass sub, jclass sup);

		jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic);

		jint Throw(jthrowable obj);
		jint ThrowNew(jclass clazz, const char *msg);
		jthrowable ExceptionOccurred();
		void  ExceptionDescribe();
		void  ExceptionClear();
		void  FatalError(const char *msg);

		jint PushLocalFrame(jint capacity);
		jobject PopLocalFrame(jobject result);

		jobject NewGlobalRef(jobject lobj);
		void  DeleteGlobalRef(jobject gref);
		void  DeleteLocalRef(jobject obj);
		jboolean IsSameObject(jobject obj1, jobject obj2);
		jobject NewLocalRef(jobject ref);
		jint EnsureLocalCapacity(jint capacity);

		jobject AllocObject(jclass clazz);
		jobject NewObjectA(jclass clazz, jmethodID methodID, const jvalue *args);

		jclass GetObjectClass(jobject obj);
		jboolean IsInstanceOf(jobject obj, jclass clazz);

		jmethodID GetMethodID(jclass clazz, const char *name, const char *sig);

		jobject CallObjectMethodA(jobject obj, jmethodID methodID, const jvalue * args);

		jboolean CallBooleanMethodA(jobject obj, jmethodID methodID, const jvalue * args);

		jbyte CallByteMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jchar CallCharMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jshort CallShortMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jint CallIntMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jlong CallLongMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jfloat CallFloatMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		jdouble CallDoubleMethodA(jobject obj, jmethodID methodID, const jvalue *args);

		void  CallVoidMethodA(jobject obj, jmethodID methodID, const jvalue * args);

		jobject CallNonvirtualObjectMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue * args);

		jboolean CallNonvirtualBooleanMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue * args);

		jbyte CallNonvirtualByteMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jchar CallNonvirtualCharMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jshort CallNonvirtualShortMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jint CallNonvirtualIntMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jlong CallNonvirtualLongMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jfloat CallNonvirtualFloatMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		jdouble CallNonvirtualDoubleMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue *args);

		void  CallNonvirtualVoidMethodA(jobject obj, jclass clazz, jmethodID methodID, const jvalue * args);

		jfieldID GetFieldID(jclass clazz, const char *name, const char *sig);

		jobject GetObjectField(jobject obj, jfieldID fieldID);
		jboolean GetBooleanField(jobject obj, jfieldID fieldID);
		jbyte GetByteField(jobject obj, jfieldID fieldID);
		jchar GetCharField(jobject obj, jfieldID fieldID);
		jshort GetShortField(jobject obj, jfieldID fieldID);
		jint GetIntField(jobject obj, jfieldID fieldID);
		jlong GetLongField(jobject obj, jfieldID fieldID);
		jfloat GetFloatField(jobject obj, jfieldID fieldID);
		jdouble GetDoubleField(jobject obj, jfieldID fieldID);

		void  SetObjectField(jobject obj, jfieldID fieldID, jobject val);
		void  SetBooleanField(jobject obj, jfieldID fieldID, jboolean val);
		void  SetByteField(jobject obj, jfieldID fieldID, jbyte val);
		void  SetCharField(jobject obj, jfieldID fieldID, jchar val);
		void  SetShortField(jobject obj, jfieldID fieldID, jshort val);
		void  SetIntField(jobject obj, jfieldID fieldID, jint val);
		void  SetLongField(jobject obj, jfieldID fieldID, jlong val);
		void  SetFloatField(jobject obj, jfieldID fieldID, jfloat val);
		void  SetDoubleField(jobject obj, jfieldID fieldID, jdouble val);

		jmethodID GetStaticMethodID(jclass clazz, const char *name, const char *sig);

		jobject CallStaticObjectMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jboolean CallStaticBooleanMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jbyte CallStaticByteMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jchar CallStaticCharMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jshort CallStaticShortMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jint CallStaticIntMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jlong CallStaticLongMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jfloat CallStaticFloatMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		jdouble CallStaticDoubleMethodA(jclass clazz, jmethodID methodID, const jvalue *args);

		void  CallStaticVoidMethodA(jclass cls, jmethodID methodID, const jvalue * args);

		jfieldID GetStaticFieldID(jclass clazz, const char *name, const char *sig);
		jobject GetStaticObjectField(jclass clazz, jfieldID fieldID);
		jboolean GetStaticBooleanField(jclass clazz, jfieldID fieldID);
		jbyte GetStaticByteField(jclass clazz, jfieldID fieldID);
		jchar GetStaticCharField(jclass clazz, jfieldID fieldID);
		jshort GetStaticShortField(jclass clazz, jfieldID fieldID);
		jint GetStaticIntField(jclass clazz, jfieldID fieldID);
		jlong GetStaticLongField(jclass clazz, jfieldID fieldID);
		jfloat GetStaticFloatField(jclass clazz, jfieldID fieldID);
		jdouble GetStaticDoubleField(jclass clazz, jfieldID fieldID);

		void  SetStaticObjectField(jclass clazz, jfieldID fieldID, jobject value);
		void  SetStaticBooleanField(jclass clazz, jfieldID fieldID, jboolean value);
		void  SetStaticByteField(jclass clazz, jfieldID fieldID, jbyte value);
		void  SetStaticCharField(jclass clazz, jfieldID fieldID, jchar value);
		void  SetStaticShortField(jclass clazz, jfieldID fieldID, jshort value);
		void  SetStaticIntField(jclass clazz, jfieldID fieldID, jint value);
		void  SetStaticLongField(jclass clazz, jfieldID fieldID, jlong value);
		void  SetStaticFloatField(jclass clazz, jfieldID fieldID, jfloat value);
		void  SetStaticDoubleField(jclass clazz, jfieldID fieldID, jdouble value);

		jstring NewString(const jchar *unicode, jsize len);
		jsize GetStringLength(jstring str);
		const jchar * GetStringChars(jstring str, jboolean *isCopy);
		void  ReleaseStringChars(jstring str, const jchar *chars);

		jstring NewStringUTF(const char *utf);
		jsize GetStringUTFLength(jstring str);
		const char*  GetStringUTFChars(jstring str, jboolean *isCopy);
		void  ReleaseStringUTFChars(jstring str, const char* chars);


		jsize GetArrayLength(jarray array);

		jobjectArray NewObjectArray(jsize len, jclass clazz, jobject init);
		jobject GetObjectArrayElement(jobjectArray array, jsize index);
		void  SetObjectArrayElement(jobjectArray array, jsize index, jobject val);

		jbooleanArray NewBooleanArray(jsize len);
		jbyteArray NewByteArray(jsize len);
		jcharArray NewCharArray(jsize len);
		jshortArray NewShortArray(jsize len);
		jintArray NewIntArray(jsize len);
		jlongArray NewLongArray(jsize len);
		jfloatArray NewFloatArray(jsize len);
		jdoubleArray NewDoubleArray(jsize len);

		jboolean *  GetBooleanArrayElements(jbooleanArray array, jboolean *isCopy);
		jbyte *  GetByteArrayElements(jbyteArray array, jboolean *isCopy);
		jchar *  GetCharArrayElements(jcharArray array, jboolean *isCopy);
		jshort *  GetShortArrayElements(jshortArray array, jboolean *isCopy);
		jint *  GetIntArrayElements(jintArray array, jboolean *isCopy);
		jlong *  GetLongArrayElements(jlongArray array, jboolean *isCopy);
		jfloat *  GetFloatArrayElements(jfloatArray array, jboolean *isCopy);
		jdouble *  GetDoubleArrayElements(jdoubleArray array, jboolean *isCopy);

		void  ReleaseBooleanArrayElements(jbooleanArray array, jboolean *elems, jint mode);
		void  ReleaseByteArrayElements(jbyteArray array, jbyte *elems, jint mode);
		void  ReleaseCharArrayElements(jcharArray array, jchar *elems, jint mode);
		void  ReleaseShortArrayElements(jshortArray array, jshort *elems, jint mode);
		void  ReleaseIntArrayElements(jintArray array, jint *elems, jint mode);
		void  ReleaseLongArrayElements(jlongArray array, jlong *elems, jint mode);
		void  ReleaseFloatArrayElements(jfloatArray array, jfloat *elems, jint mode);
		void  ReleaseDoubleArrayElements(jdoubleArray array, jdouble *elems, jint mode);

		void  GetBooleanArrayRegion(jbooleanArray array, jsize start, jsize l, jboolean *buf);
		void  GetByteArrayRegion(jbyteArray array, jsize start, jsize len, jbyte *buf);
		void  GetCharArrayRegion(jcharArray array, jsize start, jsize len, jchar *buf);
		void  GetShortArrayRegion(jshortArray array, jsize start, jsize len, jshort *buf);
		void  GetIntArrayRegion(jintArray array, jsize start, jsize len, jint *buf);
		void  GetLongArrayRegion(jlongArray array, jsize start, jsize len, jlong *buf);
		void  GetFloatArrayRegion(jfloatArray array, jsize start, jsize len, jfloat *buf);
		void  GetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, jdouble *buf);

		void  SetBooleanArrayRegion(jbooleanArray array, jsize start, jsize l, const jboolean *buf);
		void  SetByteArrayRegion(jbyteArray array, jsize start, jsize len, const jbyte *buf);
		void  SetCharArrayRegion(jcharArray array, jsize start, jsize len, const jchar *buf);
		void  SetShortArrayRegion(jshortArray array, jsize start, jsize len, const jshort *buf);
		void  SetIntArrayRegion(jintArray array, jsize start, jsize len, const jint *buf);
		void  SetLongArrayRegion(jlongArray array, jsize start, jsize len, const jlong *buf);
		void  SetFloatArrayRegion(jfloatArray array, jsize start, jsize len, const jfloat *buf);
		void  SetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, const jdouble *buf);

		void  GetStringRegion(jstring str, jsize start, jsize len, jchar *buf);
		void  GetStringUTFRegion(jstring str, jsize start, jsize len, char *buf);

		void *  GetPrimitiveArrayCritical(jarray array, jboolean *isCopy);
		void  ReleasePrimitiveArrayCritical(jarray array, void *carray, jint mode);

		const jchar *  GetStringCritical(jstring string, jboolean *isCopy);
		void  ReleaseStringCritical(jstring string, const jchar *cstring);

		jboolean ExceptionCheck();

		jobject NewDirectByteBuffer(JNIEnv* env, void* address, jlong capacity);
		void*  GetDirectBufferAddress(JNIEnv* env, jobject buf);
		jlong GetDirectBufferCapacity(JNIEnv* env, jobject buf);

		JavaVM* _VM;
		JNIEnv* _ENV;
	private:
		blackbone::Process _InnerProcess;
		blackbone::ThreadPtr _WorkerThread;
		blackbone::ModuleDataPtr _JVMModule;
		
		JNIInvokeInterface_ vmFuncs;
		JNINativeInterface_ envFuncs;

		template<typename T>
		auto GetStandardMethodFromExport(const char* name);

		jint JNI_GetCreatedJavaVMs(JavaVM** vmBuf, jsize bufLen, jsize* nVMs);

		JNIInvokeInterface_ GetInvokeInterface();

		jint GetEnv(void** penv, jint version);
		jint AttachCurrentThread(void** penv, void* args);

		JNINativeInterface_ GetNativeInterface();
	};
}


	