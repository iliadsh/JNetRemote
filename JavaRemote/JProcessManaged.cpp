#include "JProcessManaged.h"
#include <iostream>
#include <vcclr.h>

JavaRemote::JInt^ JavaRemote::JNI::GetVersion() {
	return gcnew JInt(_jni->GetVersion());
}

JavaRemote::JClass^ JavaRemote::JNI::FindClass(String^ name) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	return gcnew JClass(_jni->FindClass(cName));
}

JavaRemote::JMethodID^ JavaRemote::JNI::FromReflectedMethod(JObject^ method) {
	return gcnew JMethodID(_jni->FromReflectedMethod(method->_obj));
}
JavaRemote::JFieldID^ JavaRemote::JNI::FromReflectedField(JObject^ field) {
	return gcnew JFieldID(_jni->FromReflectedField(field->_obj));
}

JavaRemote::JObject^ JavaRemote::JNI::ToReflectedMethod(JClass^ cls, JMethodID^ methodID, JBoolean^ isStatic) {
	return gcnew JObject(_jni->ToReflectedMethod(cls->_class, methodID->_methodId, isStatic->_boolean));
}

JavaRemote::JClass^ JavaRemote::JNI::GetSuperclass(JClass^ sub) {
	return gcnew JClass(_jni->GetSuperclass(sub->_class));
}
JavaRemote::JBoolean^ JavaRemote::JNI::IsAssignableFrom(JClass^ sub, JClass^ sup) {
	return gcnew JBoolean(_jni->IsAssignableFrom(sub->_class, sup->_class));
}

JavaRemote::JObject^ JavaRemote::JNI::ToReflectedField(JClass^ cls, JFieldID^ fieldID, JBoolean^ isStatic) {
	return gcnew JObject(_jni->ToReflectedField(cls->_class, fieldID->_fieldID, isStatic->_boolean));
}

JavaRemote::JInt^ JavaRemote::JNI::Throw(JThrowable^ obj) {
	return gcnew JInt(_jni->Throw(obj->_throwable));
}
JavaRemote::JInt^ JavaRemote::JNI::ThrowNew(JClass^ clazz, String^ msg) {
	const char* cMsg = (const char*)(Marshal::StringToHGlobalAnsi(msg)).ToPointer();
	return gcnew JInt(_jni->ThrowNew(clazz->_class, cMsg));
}

JavaRemote::JThrowable^ JavaRemote::JNI::ExceptionOccurred() {
	return gcnew JThrowable(_jni->ExceptionOccurred());
}
void JavaRemote::JNI::ExceptionDescribe() {
	_jni->ExceptionDescribe();
}

void JavaRemote::JNI::ExceptionClear() {
	_jni->ExceptionClear();
}

void JavaRemote::JNI::FatalError(String^ msg) {
	const char* cMsg = (const char*)(Marshal::StringToHGlobalAnsi(msg)).ToPointer();
	_jni->FatalError(cMsg);
}

JavaRemote::JInt^ JavaRemote::JNI::PushLocalFrame(JInt^ capacity) {
	return gcnew JInt(_jni->PushLocalFrame(capacity->_int));
}
JavaRemote::JObject^ JavaRemote::JNI::PopLocalFrame(JObject^ result) {
	return gcnew JObject(_jni->PopLocalFrame(result->_obj));
}

JavaRemote::JObject^ JavaRemote::JNI::NewGlobalRef(JObject^ lobj) {
	return gcnew JObject(_jni->NewGlobalRef(lobj->_obj));
}
void  JavaRemote::JNI::DeleteGlobalRef(JObject^ gref) {
	_jni->DeleteGlobalRef(gref->_obj);
}
void  JavaRemote::JNI::DeleteLocalRef(JObject^ obj) {
	_jni->DeleteLocalRef(obj->_obj);
}
JavaRemote::JBoolean^ JavaRemote::JNI::IsSameObject(JObject^ obj1, JObject^ obj2) {
	return gcnew JBoolean(_jni->IsSameObject(obj1->_obj, obj2->_obj));
}
JavaRemote::JObject^ JavaRemote::JNI::NewLocalRef(JObject^ ref) {
	return gcnew JObject(_jni->NewLocalRef(ref->_obj));
}
JavaRemote::JInt^ JavaRemote::JNI::EnsureLocalCapacity(JInt^ capacity) {
	return gcnew JInt(_jni->EnsureLocalCapacity(capacity->_int));
}

JavaRemote::JObject^ JavaRemote::JNI::AllocObject(JClass^ clazz) {
	return gcnew JObject(_jni->AllocObject(clazz->_class));
}
JavaRemote::JObject^ JavaRemote::JNI::NewObject(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->NewObjectA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JClass^ JavaRemote::JNI::GetObjectClass(JObject^ obj) {
	return gcnew JClass(_jni->GetObjectClass(obj->_obj));
}
JavaRemote::JBoolean^ JavaRemote::JNI::IsInstanceOf(JObject^ obj, JClass^ clazz) {
	return gcnew JBoolean(_jni->IsInstanceOf(obj->_obj, clazz->_class));
}

JavaRemote::JMethodID^ JavaRemote::JNI::GetMethodID(JavaRemote::JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JavaRemote::JMethodID(_jni->GetMethodID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JNI::CallObjectMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallObjectMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JNI::CallBooleanMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallBooleanMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JNI::CallByteMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallByteMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JNI::CallCharMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallCharMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JNI::CallShortMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallShortMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JNI::CallIntMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallIntMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JNI::CallLongMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallLongMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JNI::CallFloatMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallFloatMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JNI::CallDoubleMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallDoubleMethodA(obj->_obj, methodID->_methodId, vals));
}

void  JavaRemote::JNI::CallVoidMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallVoidMethodA(obj->_obj, methodID->_methodId, vals);
}

JavaRemote::JObject^ JavaRemote::JNI::CallNonvirtualObjectMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallNonvirtualObjectMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JNI::CallNonvirtualBooleanMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallNonvirtualBooleanMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JNI::CallNonvirtualByteMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallNonvirtualByteMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JNI::CallNonvirtualCharMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallNonvirtualCharMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JNI::CallNonvirtualShortMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallNonvirtualShortMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JNI::CallNonvirtualIntMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallNonvirtualIntMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JNI::CallNonvirtualLongMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallNonvirtualLongMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JNI::CallNonvirtualFloatMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallNonvirtualFloatMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JNI::CallNonvirtualDoubleMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallNonvirtualDoubleMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

void  JavaRemote::JNI::CallNonvirtualVoidMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallNonvirtualVoidMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals);
}

JavaRemote::JFieldID^ JavaRemote::JNI::GetFieldID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JFieldID(_jni->GetFieldID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JNI::GetObjectField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JObject(_jni->GetObjectField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JBoolean^ JavaRemote::JNI::GetBooleanField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JBoolean(_jni->GetBooleanField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JByte^ JavaRemote::JNI::GetByteField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JByte(_jni->GetByteField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JChar^ JavaRemote::JNI::GetCharField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JChar(_jni->GetCharField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JShort^ JavaRemote::JNI::GetShortField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JShort(_jni->GetShortField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JInt^ JavaRemote::JNI::GetIntField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JInt(_jni->GetIntField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JLong^ JavaRemote::JNI::GetLongField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JLong(_jni->GetLongField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JFloat^ JavaRemote::JNI::GetFloatField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JFloat(_jni->GetFloatField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JDouble^ JavaRemote::JNI::GetDoubleField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JDouble(_jni->GetDoubleField(obj->_obj, fieldID->_fieldID));
}

void  JavaRemote::JNI::SetObjectField(JObject^ obj, JFieldID^ fieldID, JObject^ val) {
	_jni->SetObjectField(obj->_obj, fieldID->_fieldID, val->_obj);
}
void  JavaRemote::JNI::SetBooleanField(JObject^ obj, JFieldID^ fieldID, JBoolean^ val) {
	_jni->SetBooleanField(obj->_obj, fieldID->_fieldID, val->_boolean);
}
void  JavaRemote::JNI::SetByteField(JObject^ obj, JFieldID^ fieldID, JByte^ val) {
	_jni->SetByteField(obj->_obj, fieldID->_fieldID, val->_byte);
}
void  JavaRemote::JNI::SetCharField(JObject^ obj, JFieldID^ fieldID, JChar^ val) {
	_jni->SetCharField(obj->_obj, fieldID->_fieldID, val->_char);
}
void  JavaRemote::JNI::SetShortField(JObject^ obj, JFieldID^ fieldID, JShort^ val) {
	_jni->SetShortField(obj->_obj, fieldID->_fieldID, val->_short);
}
void  JavaRemote::JNI::SetIntField(JObject^ obj, JFieldID^ fieldID, JInt^ val) {
	_jni->SetIntField(obj->_obj, fieldID->_fieldID, val->_int);
}
void  JavaRemote::JNI::SetLongField(JObject^ obj, JFieldID^ fieldID, JLong^ val) {
	_jni->SetLongField(obj->_obj, fieldID->_fieldID, val->_long);
}
void  JavaRemote::JNI::SetFloatField(JObject^ obj, JFieldID^ fieldID, JFloat^ val) {
	_jni->SetFloatField(obj->_obj, fieldID->_fieldID, val->_float);
}
void  JavaRemote::JNI::SetDoubleField(JObject^ obj, JFieldID^ fieldID, JDouble^ val) {
	_jni->SetDoubleField(obj->_obj, fieldID->_fieldID, val->_double);
}

JavaRemote::JMethodID^ JavaRemote::JNI::GetStaticMethodID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JMethodID(_jni->GetStaticMethodID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JNI::CallStaticObjectMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallStaticObjectMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JNI::CallStaticBooleanMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallStaticBooleanMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JNI::CallStaticByteMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallStaticByteMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JNI::CallStaticCharMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallStaticCharMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JNI::CallStaticShortMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallStaticShortMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JNI::CallStaticIntMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallStaticIntMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JNI::CallStaticLongMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallStaticLongMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JNI::CallStaticFloatMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallStaticFloatMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JNI::CallStaticDoubleMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallStaticDoubleMethodA(clazz->_class, methodID->_methodId, vals));
}

void  JavaRemote::JNI::CallStaticVoidMethod(JClass^ cls, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallStaticVoidMethodA(cls->_class, methodID->_methodId, vals);
}

JavaRemote::JFieldID^ JavaRemote::JNI::GetStaticFieldID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JFieldID(_jni->GetStaticFieldID(clazz->_class, cName, cSig));
}
JavaRemote::JObject^ JavaRemote::JNI::GetStaticObjectField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JObject(_jni->GetStaticObjectField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JBoolean^ JavaRemote::JNI::GetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JBoolean(_jni->GetStaticBooleanField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JByte^ JavaRemote::JNI::GetStaticByteField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JByte(_jni->GetStaticByteField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JChar^ JavaRemote::JNI::GetStaticCharField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JChar(_jni->GetStaticCharField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JShort^ JavaRemote::JNI::GetStaticShortField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JShort(_jni->GetStaticShortField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JInt^ JavaRemote::JNI::GetStaticIntField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JInt(_jni->GetStaticIntField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JLong^ JavaRemote::JNI::GetStaticLongField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JLong(_jni->GetStaticLongField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JFloat^ JavaRemote::JNI::GetStaticFloatField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JFloat(_jni->GetStaticFloatField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JDouble^ JavaRemote::JNI::GetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JDouble(_jni->GetStaticDoubleField(clazz->_class, fieldID->_fieldID));
}

void  JavaRemote::JNI::SetStaticObjectField(JClass^ clazz, JFieldID^ fieldID, JObject^ value) {
	_jni->SetStaticObjectField(clazz->_class, fieldID->_fieldID, value->_obj);
}
void  JavaRemote::JNI::SetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID, JBoolean^ value) {
	_jni->SetStaticBooleanField(clazz->_class, fieldID->_fieldID, value->_boolean);
}
void  JavaRemote::JNI::SetStaticByteField(JClass^ clazz, JFieldID^ fieldID, JByte^ value) {
	_jni->SetStaticByteField(clazz->_class, fieldID->_fieldID, value->_byte);
}
void  JavaRemote::JNI::SetStaticCharField(JClass^ clazz, JFieldID^ fieldID, JChar^ value) {
	_jni->SetStaticCharField(clazz->_class, fieldID->_fieldID, value->_char);
}
void  JavaRemote::JNI::SetStaticShortField(JClass^ clazz, JFieldID^ fieldID, JShort^ value) {
	_jni->SetStaticShortField(clazz->_class, fieldID->_fieldID, value->_short);
}
void  JavaRemote::JNI::SetStaticIntField(JClass^ clazz, JFieldID^ fieldID, JInt^ value) {
	_jni->SetStaticIntField(clazz->_class, fieldID->_fieldID, value->_int);
}
void  JavaRemote::JNI::SetStaticLongField(JClass^ clazz, JFieldID^ fieldID, JLong^ value) {
	_jni->SetStaticLongField(clazz->_class, fieldID->_fieldID, value->_long);
}
void  JavaRemote::JNI::SetStaticFloatField(JClass^ clazz, JFieldID^ fieldID, JFloat^ value) {
	_jni->SetStaticFloatField(clazz->_class, fieldID->_fieldID, value->_float);
}
void  JavaRemote::JNI::SetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID, JDouble^ value) {
	_jni->SetStaticDoubleField(clazz->_class, fieldID->_fieldID, value->_double);
}

JavaRemote::JString^ JavaRemote::JNI::NewString(String^ unicode) {
	pin_ptr<const wchar_t> ptr = PtrToStringChars(unicode);
	jchar* str = new jchar[unicode->Length];
	for (int i = 0; i < unicode->Length; i++) {
		str[i] = (unsigned short)(ptr[i]);
	}
	return gcnew JString(_jni->NewString(str, unicode->Length));
}
JavaRemote::JInt^ JavaRemote::JNI::GetStringLength(JString^ str) {
	return gcnew JInt(_jni->GetStringLength(str->_string));
}
array<JavaRemote::JChar^>^ JavaRemote::JNI::GetStringChars(JString^ str, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	const jchar* chars = _jni->GetStringChars(str->_string, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetStringLength(str->_string);
	array<JChar^>^ retchars = gcnew array<JChar^>(size);
	for (int i = 0; i < size; i++) {
		retchars[i] = gcnew JChar(chars[i]);
	}
	return retchars;
}
void  JavaRemote::JNI::ReleaseStringChars(JString^ str, array<JChar^>^ chars) {
	jchar* jchars = new jchar[chars->GetLength(0)];
	for (int i = 0; i < chars->GetLength(0); i++) {
		jchars[i] = chars[i]->Value();
	}
	_jni->ReleaseStringChars(str->_string, jchars);
}

JavaRemote::JString^ JavaRemote::JNI::NewStringUTF(String^ utf) {
	const char* cChars = (const char*)(Marshal::StringToHGlobalAnsi(utf)).ToPointer();
	return gcnew JString(_jni->NewStringUTF(cChars));
}
JavaRemote::JInt^ JavaRemote::JNI::GetStringUTFLength(JString^ str) {
	return gcnew JInt(_jni->GetStringUTFLength(str->_string));
}
String^ JavaRemote::JNI::GetStringUTFChars(JString^ str, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	const char* cString = _jni->GetStringUTFChars(str->_string, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	return gcnew String(cString);
}
void  JavaRemote::JNI::ReleaseStringUTFChars(JString^ str, String^ chars) {
	const char* cChars = (const char*)(Marshal::StringToHGlobalAnsi(chars)).ToPointer();
	_jni->ReleaseStringUTFChars(str->_string, cChars);
}


JavaRemote::JInt^ JavaRemote::JNI::GetArrayLength(JArray^ array) {
	return gcnew JInt(_jni->GetArrayLength(array->_array));
}

JavaRemote::JObjectArray^ JavaRemote::JNI::NewObjectArray(JInt^ len, JClass^ clazz, JObject^ init) {
	return gcnew JObjectArray(_jni->NewObjectArray(len->_int, clazz->_class, init->_obj));
}
JavaRemote::JObject^ JavaRemote::JNI::GetObjectArrayElement(JObjectArray^ array, JInt^ index) {
	return gcnew JObject(_jni->GetObjectArrayElement(array->_objectArrary, index->_int));
}
void  JavaRemote::JNI::SetObjectArrayElement(JObjectArray^ array, JInt^ index, JObject^ val) {
	_jni->SetObjectArrayElement(array->_objectArrary, index->_int, val->_obj);
}

JavaRemote::JBooleanArray^ JavaRemote::JNI::NewBooleanArray(JInt^ len) {
	return gcnew JBooleanArray(_jni->NewBooleanArray(len->_int));
}
JavaRemote::JByteArray^ JavaRemote::JNI::NewByteArray(JInt^ len) {
	return gcnew JByteArray(_jni->NewByteArray(len->_int));
}
JavaRemote::JCharArray^ JavaRemote::JNI::NewCharArray(JInt^ len) {
	return gcnew JCharArray(_jni->NewCharArray(len->_int));
}
JavaRemote::JShortArray^ JavaRemote::JNI::NewShortArray(JInt^ len) {
	return gcnew JShortArray(_jni->NewShortArray(len->_int));
}
JavaRemote::JIntArray^ JavaRemote::JNI::NewIntArray(JInt^ len) {
	return gcnew JIntArray(_jni->NewIntArray(len->_int));
}
JavaRemote::JLongArray^ JavaRemote::JNI::NewLongArray(JInt^ len) {
	return gcnew JLongArray(_jni->NewLongArray(len->_int));
}
JavaRemote::JFloatArray^ JavaRemote::JNI::NewFloatArray(JInt^ len) {
	return gcnew JFloatArray(_jni->NewFloatArray(len->_int));
}
JavaRemote::JDoubleArray^ JavaRemote::JNI::NewDoubleArray(JInt^ len) {
	return gcnew JDoubleArray(_jni->NewDoubleArray(len->_int));
}

array<JavaRemote::JBoolean^>^ JavaRemote::JNI::GetBooleanArrayElements(JBooleanArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jboolean* arr = _jni->GetBooleanArrayElements(aarray->_booleanArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JBoolean^>^ retarr = gcnew array<JBoolean^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JBoolean(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JByte^>^  JavaRemote::JNI::GetByteArrayElements(JByteArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jbyte* arr = _jni->GetByteArrayElements(aarray->_byteArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JByte^>^ retarr = gcnew array<JByte^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JByte(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JChar^>^  JavaRemote::JNI::GetCharArrayElements(JCharArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jchar* arr = _jni->GetCharArrayElements(aarray->_charArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JChar^>^ retarr = gcnew array<JChar^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JChar(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JShort^>^  JavaRemote::JNI::GetShortArrayElements(JShortArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jshort* arr = _jni->GetShortArrayElements(aarray->_shortArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JShort^>^ retarr = gcnew array<JShort^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JShort(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JInt^>^ JavaRemote::JNI::GetIntArrayElements(JIntArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jint* arr = _jni->GetIntArrayElements(aarray->_intArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JInt^>^ retarr = gcnew array<JInt^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JInt(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JLong^>^ JavaRemote::JNI::GetLongArrayElements(JLongArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jlong* arr = _jni->GetLongArrayElements(aarray->_longArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JLong^>^ retarr = gcnew array<JLong^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JLong(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JFloat^>^  JavaRemote::JNI::GetFloatArrayElements(JFloatArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jfloat* arr = _jni->GetFloatArrayElements(aarray->_floatArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JFloat^>^ retarr = gcnew array<JFloat^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JFloat(arr[i]);
	}
	return retarr;
}
array<JavaRemote::JDouble^>^ JavaRemote::JNI::GetDoubleArrayElements(JDoubleArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	jdouble* arr = _jni->GetDoubleArrayElements(aarray->_doubleArray, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetArrayLength(aarray->_array);
	array<JDouble^>^ retarr = gcnew array<JDouble^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JDouble(arr[i]);
	}
	return retarr;
}

void  JavaRemote::JNI::ReleaseBooleanArrayElements(JBooleanArray^ aarray, array<JBoolean^>^ elems, JInt^ mode) {
	jboolean* celems = new jboolean[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->_boolean;
	}
	_jni->ReleaseBooleanArrayElements(aarray->_booleanArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseByteArrayElements(JByteArray^ aarray, array<JByte^>^ elems, JInt^ mode) {
	jbyte* celems = new jbyte[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseByteArrayElements(aarray->_byteArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseCharArrayElements(JCharArray^ aarray, array<JChar^>^ elems, JInt^ mode) {
	jchar* celems = new jchar[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseCharArrayElements(aarray->_charArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseShortArrayElements(JShortArray^ aarray, array<JShort^>^ elems, JInt^ mode) {
	jshort* celems = new jshort[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseShortArrayElements(aarray->_shortArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseIntArrayElements(JIntArray^ aarray, array<JInt^>^ elems, JInt^ mode) {
	jint* celems = new jint[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseIntArrayElements(aarray->_intArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseLongArrayElements(JLongArray^ aarray, array<JLong^>^ elems, JInt^ mode) {
	jlong* celems = new jlong[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseLongArrayElements(aarray->_longArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseFloatArrayElements(JFloatArray^ aarray, array<JFloat^>^ elems, JInt^ mode) {
	jfloat* celems = new jfloat[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseFloatArrayElements(aarray->_floatArray, celems, mode->_int);
}
void  JavaRemote::JNI::ReleaseDoubleArrayElements(JDoubleArray^ aarray, array<JDouble^>^ elems, JInt^ mode) {
	jdouble* celems = new jdouble[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseDoubleArrayElements(aarray->_doubleArray, celems, mode->_int);
}

void  JavaRemote::JNI::GetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, [OutAttribute] array<JBoolean^>^% buf) {
	jboolean* cbuf;
	_jni->GetBooleanArrayRegion(aarray->_booleanArray, start->_int, l->_int, cbuf);
	buf = gcnew array<JBoolean^>(l->_int - start->_int);
	for (int i = 0; i < (l->_int - start->_int); i++) {
		buf[i] = gcnew JBoolean(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JByte^>^% buf) {
	jbyte* cbuf;
	_jni->GetByteArrayRegion(aarray->_byteArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JByte^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JByte(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf) {
	jchar* cbuf;
	_jni->GetCharArrayRegion(aarray->_charArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JChar^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JChar(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JShort^>^% buf) {
	jshort* cbuf;
	_jni->GetShortArrayRegion(aarray->_shortArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JShort^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JShort(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JInt^>^% buf) {
	jint* cbuf;
	_jni->GetIntArrayRegion(aarray->_intArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JInt^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JInt(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JLong^>^% buf) {
	jlong* cbuf;
	_jni->GetLongArrayRegion(aarray->_longArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JLong^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JLong(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JFloat^>^% buf) {
	jfloat* cbuf;
	_jni->GetFloatArrayRegion(aarray->_floatArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JFloat^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JFloat(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JDouble^>^% buf) {
	jdouble* cbuf;
	_jni->GetDoubleArrayRegion(aarray->_doubleArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JDouble^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JDouble(cbuf[i]);
	}
}

void  JavaRemote::JNI::SetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, array<JBoolean^>^ buf) {
	jboolean* cbuf = new jboolean[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->_boolean;
	}
	_jni->SetBooleanArrayRegion(aarray->_booleanArray, start->_int, l->_int, cbuf);
}
void  JavaRemote::JNI::SetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, array<JByte^>^ buf) {
	jbyte* cbuf = new jbyte[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetByteArrayRegion(aarray->_byteArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, array<JChar^>^ buf) {
	jchar* cbuf = new jchar[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetCharArrayRegion(aarray->_charArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, array<JShort^>^ buf) {
	jshort* cbuf = new jshort[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetShortArrayRegion(aarray->_shortArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, array<JInt^>^ buf) {
	jint* cbuf = new jint[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetIntArrayRegion(aarray->_intArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, array<JLong^>^ buf) {
	jlong* cbuf = new jlong[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetLongArrayRegion(aarray->_longArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, array<JFloat^>^ buf) {
	jfloat* cbuf = new jfloat[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetFloatArrayRegion(aarray->_floatArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JNI::SetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, array<JDouble^>^ buf) {
	jdouble* cbuf = new jdouble[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetDoubleArrayRegion(aarray->_doubleArray, start->_int, len->_int, cbuf);
}

void  JavaRemote::JNI::GetStringRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf) {
	jchar* cbuf;
	_jni->GetStringRegion(str->_string, start->_int, len->_int, cbuf);
	buf = gcnew array<JChar^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JChar(cbuf[i]);
	}
}
void  JavaRemote::JNI::GetStringUTFRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] String^% buf) {
	char* cbuf;
	_jni->GetStringUTFRegion(str->_string, start->_int, len->_int, cbuf);
	buf = gcnew String(cbuf);
}

IntPtr JavaRemote::JNI::GetPrimitiveArrayCritical(JArray^ array, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	void* arr = _jni->GetPrimitiveArrayCritical(array->_array, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	return IntPtr(arr);
}
void  JavaRemote::JNI::ReleasePrimitiveArrayCritical(JArray^ array, IntPtr carray, JInt^ mode) {
	_jni->ReleasePrimitiveArrayCritical(array->_array, carray.ToPointer(), mode->_int);
}

array<JavaRemote::JChar^>^ JavaRemote::JNI::GetStringCritical(JString^ string, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	const jchar* arr = _jni->GetStringCritical(string->_string, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	jsize size = _jni->GetStringLength(string->_string);
	array<JChar^>^ retarr = gcnew array<JChar^>(size);
	for (int i = 0; i < size; i++) {
		retarr[i] = gcnew JChar(arr[i]);
	}
	return retarr;
}
void  JavaRemote::JNI::ReleaseStringCritical(JString^ string, array<JChar^>^ cstring) {
	jchar* arr = new jchar[cstring->Length];
	for (int i = 0; i < cstring->Length; i++) {
		arr[i] = cstring[i]->Value();
	}
	_jni->ReleaseStringCritical(string->_string, arr);
}

JavaRemote::JBoolean^  JavaRemote::JNI::ExceptionCheck() {
	return gcnew JBoolean(_jni->ExceptionCheck());
}

JavaRemote::JObject^  JavaRemote::JNI::NewDirectByteBuffer(IntPtr address, JLong^ capacity) {
	return gcnew JObject(_jni->NewDirectByteBuffer(address.ToPointer(), capacity->_long));
}
IntPtr  JavaRemote::JNI::GetDirectBufferAddress(JObject^ buf) {
	return IntPtr(_jni->GetDirectBufferAddress(buf->_obj));
}
JavaRemote::JLong^  JavaRemote::JNI::GetDirectBufferCapacity(JObject^ buf) {
	return gcnew JLong(_jni->GetDirectBufferCapacity(buf->_obj));
}

bool JavaRemote::JNI::AttachVM(Process^ p, [OutAttribute] JNI^% jp) {
	for each(ProcessModule^ mod in p->Modules)
	{
		if (mod->FileName->Contains("jvm.dll"))
		{
			jp = gcnew JNI(p->Id);
			return true;
		}
	}
	return false;
}