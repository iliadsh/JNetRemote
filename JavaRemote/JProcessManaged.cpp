#include "JProcessManaged.h"
#include <iostream>
#include <vcclr.h>

JavaRemote::JInt^ JavaRemote::JProcess::GetVersion() {
	return gcnew JInt(_jni->GetVersion());
}

JavaRemote::JClass^ JavaRemote::JProcess::FindClass(String^ name) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	return gcnew JClass(_jni->FindClass(cName));
}

JavaRemote::JMethodID^ JavaRemote::JProcess::FromReflectedMethod(JObject^ method) {
	return gcnew JMethodID(_jni->FromReflectedMethod(method->_obj));
}
JavaRemote::JFieldID^ JavaRemote::JProcess::FromReflectedField(JObject^ field) {
	return gcnew JFieldID(_jni->FromReflectedField(field->_obj));
}

JavaRemote::JObject^ JavaRemote::JProcess::ToReflectedMethod(JClass^ cls, JMethodID^ methodID, JBoolean^ isStatic) {
	return gcnew JObject(_jni->ToReflectedMethod(cls->_class, methodID->_methodId, isStatic->_boolean));
}

JavaRemote::JClass^ JavaRemote::JProcess::GetSuperclass(JClass^ sub) {
	return gcnew JClass(_jni->GetSuperclass(sub->_class));
}
JavaRemote::JBoolean^ JavaRemote::JProcess::IsAssignableFrom(JClass^ sub, JClass^ sup) {
	return gcnew JBoolean(_jni->IsAssignableFrom(sub->_class, sup->_class));
}

JavaRemote::JObject^ JavaRemote::JProcess::ToReflectedField(JClass^ cls, JFieldID^ fieldID, JBoolean^ isStatic) {
	return gcnew JObject(_jni->ToReflectedField(cls->_class, fieldID->_fieldID, isStatic->_boolean));
}

JavaRemote::JInt^ JavaRemote::JProcess::Throw(JThrowable^ obj) {
	return gcnew JInt(_jni->Throw(obj->_throwable));
}
JavaRemote::JInt^ JavaRemote::JProcess::ThrowNew(JClass^ clazz, String^ msg) {
	const char* cMsg = (const char*)(Marshal::StringToHGlobalAnsi(msg)).ToPointer();
	return gcnew JInt(_jni->ThrowNew(clazz->_class, cMsg));
}

JavaRemote::JThrowable^ JavaRemote::JProcess::ExceptionOccurred() {
	return gcnew JThrowable(_jni->ExceptionOccurred());
}
void JavaRemote::JProcess::ExceptionDescribe() {
	_jni->ExceptionDescribe();
}

void JavaRemote::JProcess::ExceptionClear() {
	_jni->ExceptionClear();
}

void JavaRemote::JProcess::FatalError(String^ msg) {
	const char* cMsg = (const char*)(Marshal::StringToHGlobalAnsi(msg)).ToPointer();
	_jni->FatalError(cMsg);
}

JavaRemote::JInt^ JavaRemote::JProcess::PushLocalFrame(JInt^ capacity) {
	return gcnew JInt(_jni->PushLocalFrame(capacity->_int));
}
JavaRemote::JObject^ JavaRemote::JProcess::PopLocalFrame(JObject^ result) {
	return gcnew JObject(_jni->PopLocalFrame(result->_obj));
}

JavaRemote::JObject^ JavaRemote::JProcess::NewGlobalRef(JObject^ lobj) {
	return gcnew JObject(_jni->NewGlobalRef(lobj->_obj));
}
void  JavaRemote::JProcess::DeleteGlobalRef(JObject^ gref) {
	_jni->DeleteGlobalRef(gref->_obj);
}
void  JavaRemote::JProcess::DeleteLocalRef(JObject^ obj) {
	_jni->DeleteLocalRef(obj->_obj);
}
JavaRemote::JBoolean^ JavaRemote::JProcess::IsSameObject(JObject^ obj1, JObject^ obj2) {
	return gcnew JBoolean(_jni->IsSameObject(obj1->_obj, obj2->_obj));
}
JavaRemote::JObject^ JavaRemote::JProcess::NewLocalRef(JObject^ ref) {
	return gcnew JObject(_jni->NewLocalRef(ref->_obj));
}
JavaRemote::JInt^ JavaRemote::JProcess::EnsureLocalCapacity(JInt^ capacity) {
	return gcnew JInt(_jni->EnsureLocalCapacity(capacity->_int));
}

JavaRemote::JObject^ JavaRemote::JProcess::AllocObject(JClass^ clazz) {
	return gcnew JObject(_jni->AllocObject(clazz->_class));
}
JavaRemote::JObject^ JavaRemote::JProcess::NewObject(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->NewObjectA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JClass^ JavaRemote::JProcess::GetObjectClass(JObject^ obj) {
	return gcnew JClass(_jni->GetObjectClass(obj->_obj));
}
JavaRemote::JBoolean^ JavaRemote::JProcess::IsInstanceOf(JObject^ obj, JClass^ clazz) {
	return gcnew JBoolean(_jni->IsInstanceOf(obj->_obj, clazz->_class));
}

JavaRemote::JMethodID^ JavaRemote::JProcess::GetMethodID(JavaRemote::JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JavaRemote::JMethodID(_jni->GetMethodID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JProcess::CallObjectMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallObjectMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JProcess::CallBooleanMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallBooleanMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JProcess::CallByteMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallByteMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JProcess::CallCharMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallCharMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JProcess::CallShortMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallShortMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JProcess::CallIntMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallIntMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JProcess::CallLongMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallLongMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JProcess::CallFloatMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallFloatMethodA(obj->_obj, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JProcess::CallDoubleMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallDoubleMethodA(obj->_obj, methodID->_methodId, vals));
}

void  JavaRemote::JProcess::CallVoidMethod(JObject^ obj, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallVoidMethodA(obj->_obj, methodID->_methodId, vals);
}

JavaRemote::JObject^ JavaRemote::JProcess::CallNonvirtualObjectMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallNonvirtualObjectMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JProcess::CallNonvirtualBooleanMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallNonvirtualBooleanMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JProcess::CallNonvirtualByteMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallNonvirtualByteMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JProcess::CallNonvirtualCharMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallNonvirtualCharMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JProcess::CallNonvirtualShortMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallNonvirtualShortMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JProcess::CallNonvirtualIntMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallNonvirtualIntMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JProcess::CallNonvirtualLongMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallNonvirtualLongMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JProcess::CallNonvirtualFloatMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallNonvirtualFloatMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JProcess::CallNonvirtualDoubleMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallNonvirtualDoubleMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals));
}

void  JavaRemote::JProcess::CallNonvirtualVoidMethod(JObject^ obj, JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallNonvirtualVoidMethodA(obj->_obj, clazz->_class, methodID->_methodId, vals);
}

JavaRemote::JFieldID^ JavaRemote::JProcess::GetFieldID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JFieldID(_jni->GetFieldID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JProcess::GetObjectField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JObject(_jni->GetObjectField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JBoolean^ JavaRemote::JProcess::GetBooleanField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JBoolean(_jni->GetBooleanField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JByte^ JavaRemote::JProcess::GetByteField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JByte(_jni->GetByteField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JChar^ JavaRemote::JProcess::GetCharField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JChar(_jni->GetCharField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JShort^ JavaRemote::JProcess::GetShortField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JShort(_jni->GetShortField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JInt^ JavaRemote::JProcess::GetIntField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JInt(_jni->GetIntField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JLong^ JavaRemote::JProcess::GetLongField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JLong(_jni->GetLongField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JFloat^ JavaRemote::JProcess::GetFloatField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JFloat(_jni->GetFloatField(obj->_obj, fieldID->_fieldID));
}
JavaRemote::JDouble^ JavaRemote::JProcess::GetDoubleField(JObject^ obj, JFieldID^ fieldID) {
	return gcnew JDouble(_jni->GetDoubleField(obj->_obj, fieldID->_fieldID));
}

void  JavaRemote::JProcess::SetObjectField(JObject^ obj, JFieldID^ fieldID, JObject^ val) {
	_jni->SetObjectField(obj->_obj, fieldID->_fieldID, val->_obj);
}
void  JavaRemote::JProcess::SetBooleanField(JObject^ obj, JFieldID^ fieldID, JBoolean^ val) {
	_jni->SetBooleanField(obj->_obj, fieldID->_fieldID, val->_boolean);
}
void  JavaRemote::JProcess::SetByteField(JObject^ obj, JFieldID^ fieldID, JByte^ val) {
	_jni->SetByteField(obj->_obj, fieldID->_fieldID, val->_byte);
}
void  JavaRemote::JProcess::SetCharField(JObject^ obj, JFieldID^ fieldID, JChar^ val) {
	_jni->SetCharField(obj->_obj, fieldID->_fieldID, val->_char);
}
void  JavaRemote::JProcess::SetShortField(JObject^ obj, JFieldID^ fieldID, JShort^ val) {
	_jni->SetShortField(obj->_obj, fieldID->_fieldID, val->_short);
}
void  JavaRemote::JProcess::SetIntField(JObject^ obj, JFieldID^ fieldID, JInt^ val) {
	_jni->SetIntField(obj->_obj, fieldID->_fieldID, val->_int);
}
void  JavaRemote::JProcess::SetLongField(JObject^ obj, JFieldID^ fieldID, JLong^ val) {
	_jni->SetLongField(obj->_obj, fieldID->_fieldID, val->_long);
}
void  JavaRemote::JProcess::SetFloatField(JObject^ obj, JFieldID^ fieldID, JFloat^ val) {
	_jni->SetFloatField(obj->_obj, fieldID->_fieldID, val->_float);
}
void  JavaRemote::JProcess::SetDoubleField(JObject^ obj, JFieldID^ fieldID, JDouble^ val) {
	_jni->SetDoubleField(obj->_obj, fieldID->_fieldID, val->_double);
}

JavaRemote::JMethodID^ JavaRemote::JProcess::GetStaticMethodID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JMethodID(_jni->GetStaticMethodID(clazz->_class, cName, cSig));
}

JavaRemote::JObject^ JavaRemote::JProcess::CallStaticObjectMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JObject(_jni->CallStaticObjectMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JBoolean^ JavaRemote::JProcess::CallStaticBooleanMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JBoolean(_jni->CallStaticBooleanMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JByte^ JavaRemote::JProcess::CallStaticByteMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JByte(_jni->CallStaticByteMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JChar^ JavaRemote::JProcess::CallStaticCharMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JChar(_jni->CallStaticCharMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JShort^ JavaRemote::JProcess::CallStaticShortMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JShort(_jni->CallStaticShortMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JInt^ JavaRemote::JProcess::CallStaticIntMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JInt(_jni->CallStaticIntMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JLong^ JavaRemote::JProcess::CallStaticLongMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JLong(_jni->CallStaticLongMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JFloat^ JavaRemote::JProcess::CallStaticFloatMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JFloat(_jni->CallStaticFloatMethodA(clazz->_class, methodID->_methodId, vals));
}

JavaRemote::JDouble^ JavaRemote::JProcess::CallStaticDoubleMethod(JClass^ clazz, JMethodID^ methodID, ... array<JValue^>^args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	return gcnew JDouble(_jni->CallStaticDoubleMethodA(clazz->_class, methodID->_methodId, vals));
}

void  JavaRemote::JProcess::CallStaticVoidMethod(JClass^ cls, JMethodID^ methodID, ... array<JValue^>^ args) {
	jvalue* vals = new jvalue[args->GetLength(0)];
	for (int i = 0; i < args->GetLength(0); i++) {
		vals[i] = args[i]->GetJValue();
	}
	_jni->CallStaticVoidMethodA(cls->_class, methodID->_methodId, vals);
}

JavaRemote::JFieldID^ JavaRemote::JProcess::GetStaticFieldID(JClass^ clazz, String^ name, String^ sig) {
	const char* cName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
	const char* cSig = (const char*)(Marshal::StringToHGlobalAnsi(sig)).ToPointer();
	return gcnew JFieldID(_jni->GetStaticFieldID(clazz->_class, cName, cSig));
}
JavaRemote::JObject^ JavaRemote::JProcess::GetStaticObjectField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JObject(_jni->GetStaticObjectField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JBoolean^ JavaRemote::JProcess::GetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JBoolean(_jni->GetStaticBooleanField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JByte^ JavaRemote::JProcess::GetStaticByteField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JByte(_jni->GetStaticByteField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JChar^ JavaRemote::JProcess::GetStaticCharField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JChar(_jni->GetStaticCharField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JShort^ JavaRemote::JProcess::GetStaticShortField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JShort(_jni->GetStaticShortField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JInt^ JavaRemote::JProcess::GetStaticIntField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JInt(_jni->GetStaticIntField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JLong^ JavaRemote::JProcess::GetStaticLongField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JLong(_jni->GetStaticLongField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JFloat^ JavaRemote::JProcess::GetStaticFloatField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JFloat(_jni->GetStaticFloatField(clazz->_class, fieldID->_fieldID));
}
JavaRemote::JDouble^ JavaRemote::JProcess::GetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID) {
	return gcnew JDouble(_jni->GetStaticDoubleField(clazz->_class, fieldID->_fieldID));
}

void  JavaRemote::JProcess::SetStaticObjectField(JClass^ clazz, JFieldID^ fieldID, JObject^ value) {
	_jni->SetStaticObjectField(clazz->_class, fieldID->_fieldID, value->_obj);
}
void  JavaRemote::JProcess::SetStaticBooleanField(JClass^ clazz, JFieldID^ fieldID, JBoolean^ value) {
	_jni->SetStaticBooleanField(clazz->_class, fieldID->_fieldID, value->_boolean);
}
void  JavaRemote::JProcess::SetStaticByteField(JClass^ clazz, JFieldID^ fieldID, JByte^ value) {
	_jni->SetStaticByteField(clazz->_class, fieldID->_fieldID, value->_byte);
}
void  JavaRemote::JProcess::SetStaticCharField(JClass^ clazz, JFieldID^ fieldID, JChar^ value) {
	_jni->SetStaticCharField(clazz->_class, fieldID->_fieldID, value->_char);
}
void  JavaRemote::JProcess::SetStaticShortField(JClass^ clazz, JFieldID^ fieldID, JShort^ value) {
	_jni->SetStaticShortField(clazz->_class, fieldID->_fieldID, value->_short);
}
void  JavaRemote::JProcess::SetStaticIntField(JClass^ clazz, JFieldID^ fieldID, JInt^ value) {
	_jni->SetStaticIntField(clazz->_class, fieldID->_fieldID, value->_int);
}
void  JavaRemote::JProcess::SetStaticLongField(JClass^ clazz, JFieldID^ fieldID, JLong^ value) {
	_jni->SetStaticLongField(clazz->_class, fieldID->_fieldID, value->_long);
}
void  JavaRemote::JProcess::SetStaticFloatField(JClass^ clazz, JFieldID^ fieldID, JFloat^ value) {
	_jni->SetStaticFloatField(clazz->_class, fieldID->_fieldID, value->_float);
}
void  JavaRemote::JProcess::SetStaticDoubleField(JClass^ clazz, JFieldID^ fieldID, JDouble^ value) {
	_jni->SetStaticDoubleField(clazz->_class, fieldID->_fieldID, value->_double);
}

JavaRemote::JString^ JavaRemote::JProcess::NewString(String^ unicode) {
	pin_ptr<const wchar_t> ptr = PtrToStringChars(unicode);
	jchar* str = new jchar[unicode->Length];
	for (int i = 0; i < unicode->Length; i++) {
		str[i] = (unsigned short)(ptr[i]);
	}
	return gcnew JString(_jni->NewString(str, unicode->Length));
}
JavaRemote::JInt^ JavaRemote::JProcess::GetStringLength(JString^ str) {
	return gcnew JInt(_jni->GetStringLength(str->_string));
}
array<JavaRemote::JChar^>^ JavaRemote::JProcess::GetStringChars(JString^ str, [OutAttribute] JBoolean^% isCopy) {
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
void  JavaRemote::JProcess::ReleaseStringChars(JString^ str, array<JChar^>^ chars) {
	jchar* jchars = new jchar[chars->GetLength(0)];
	for (int i = 0; i < chars->GetLength(0); i++) {
		jchars[i] = chars[i]->Value();
	}
	_jni->ReleaseStringChars(str->_string, jchars);
}

JavaRemote::JString^ JavaRemote::JProcess::NewStringUTF(String^ utf) {
	const char* cChars = (const char*)(Marshal::StringToHGlobalAnsi(utf)).ToPointer();
	return gcnew JString(_jni->NewStringUTF(cChars));
}
JavaRemote::JInt^ JavaRemote::JProcess::GetStringUTFLength(JString^ str) {
	return gcnew JInt(_jni->GetStringUTFLength(str->_string));
}
String^ JavaRemote::JProcess::GetStringUTFChars(JString^ str, [OutAttribute] JBoolean^% isCopy) {
	jboolean* isCCopy;
	const char* cString = _jni->GetStringUTFChars(str->_string, isCCopy);
	isCopy = gcnew JBoolean(*isCCopy);
	return gcnew String(cString);
}
void  JavaRemote::JProcess::ReleaseStringUTFChars(JString^ str, String^ chars) {
	const char* cChars = (const char*)(Marshal::StringToHGlobalAnsi(chars)).ToPointer();
	_jni->ReleaseStringUTFChars(str->_string, cChars);
}


JavaRemote::JInt^ JavaRemote::JProcess::GetArrayLength(JArray^ array) {
	return gcnew JInt(_jni->GetArrayLength(array->_array));
}

JavaRemote::JObjectArray^ JavaRemote::JProcess::NewObjectArray(JInt^ len, JClass^ clazz, JObject^ init) {
	return gcnew JObjectArray(_jni->NewObjectArray(len->_int, clazz->_class, init->_obj));
}
JavaRemote::JObject^ JavaRemote::JProcess::GetObjectArrayElement(JObjectArray^ array, JInt^ index) {
	return gcnew JObject(_jni->GetObjectArrayElement(array->_objectArrary, index->_int));
}
void  JavaRemote::JProcess::SetObjectArrayElement(JObjectArray^ array, JInt^ index, JObject^ val) {
	_jni->SetObjectArrayElement(array->_objectArrary, index->_int, val->_obj);
}

JavaRemote::JBooleanArray^ JavaRemote::JProcess::NewBooleanArray(JInt^ len) {
	return gcnew JBooleanArray(_jni->NewBooleanArray(len->_int));
}
JavaRemote::JByteArray^ JavaRemote::JProcess::NewByteArray(JInt^ len) {
	return gcnew JByteArray(_jni->NewByteArray(len->_int));
}
JavaRemote::JCharArray^ JavaRemote::JProcess::NewCharArray(JInt^ len) {
	return gcnew JCharArray(_jni->NewCharArray(len->_int));
}
JavaRemote::JShortArray^ JavaRemote::JProcess::NewShortArray(JInt^ len) {
	return gcnew JShortArray(_jni->NewShortArray(len->_int));
}
JavaRemote::JIntArray^ JavaRemote::JProcess::NewIntArray(JInt^ len) {
	return gcnew JIntArray(_jni->NewIntArray(len->_int));
}
JavaRemote::JLongArray^ JavaRemote::JProcess::NewLongArray(JInt^ len) {
	return gcnew JLongArray(_jni->NewLongArray(len->_int));
}
JavaRemote::JFloatArray^ JavaRemote::JProcess::NewFloatArray(JInt^ len) {
	return gcnew JFloatArray(_jni->NewFloatArray(len->_int));
}
JavaRemote::JDoubleArray^ JavaRemote::JProcess::NewDoubleArray(JInt^ len) {
	return gcnew JDoubleArray(_jni->NewDoubleArray(len->_int));
}

array<JavaRemote::JBoolean^>^ JavaRemote::JProcess::GetBooleanArrayElements(JBooleanArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JByte^>^  JavaRemote::JProcess::GetByteArrayElements(JByteArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JChar^>^  JavaRemote::JProcess::GetCharArrayElements(JCharArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JShort^>^  JavaRemote::JProcess::GetShortArrayElements(JShortArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JInt^>^ JavaRemote::JProcess::GetIntArrayElements(JIntArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JLong^>^ JavaRemote::JProcess::GetLongArrayElements(JLongArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JFloat^>^  JavaRemote::JProcess::GetFloatArrayElements(JFloatArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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
array<JavaRemote::JDouble^>^ JavaRemote::JProcess::GetDoubleArrayElements(JDoubleArray^ aarray, [OutAttribute] JBoolean^% isCopy) {
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

void  JavaRemote::JProcess::ReleaseBooleanArrayElements(JBooleanArray^ aarray, array<JBoolean^>^ elems, JInt^ mode) {
	jboolean* celems = new jboolean[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->_boolean;
	}
	_jni->ReleaseBooleanArrayElements(aarray->_booleanArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseByteArrayElements(JByteArray^ aarray, array<JByte^>^ elems, JInt^ mode) {
	jbyte* celems = new jbyte[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseByteArrayElements(aarray->_byteArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseCharArrayElements(JCharArray^ aarray, array<JChar^>^ elems, JInt^ mode) {
	jchar* celems = new jchar[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseCharArrayElements(aarray->_charArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseShortArrayElements(JShortArray^ aarray, array<JShort^>^ elems, JInt^ mode) {
	jshort* celems = new jshort[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseShortArrayElements(aarray->_shortArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseIntArrayElements(JIntArray^ aarray, array<JInt^>^ elems, JInt^ mode) {
	jint* celems = new jint[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseIntArrayElements(aarray->_intArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseLongArrayElements(JLongArray^ aarray, array<JLong^>^ elems, JInt^ mode) {
	jlong* celems = new jlong[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseLongArrayElements(aarray->_longArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseFloatArrayElements(JFloatArray^ aarray, array<JFloat^>^ elems, JInt^ mode) {
	jfloat* celems = new jfloat[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseFloatArrayElements(aarray->_floatArray, celems, mode->_int);
}
void  JavaRemote::JProcess::ReleaseDoubleArrayElements(JDoubleArray^ aarray, array<JDouble^>^ elems, JInt^ mode) {
	jdouble* celems = new jdouble[elems->GetLength(0)];
	for (int i = 0; i < elems->GetLength(0); i++) {
		celems[i] = elems[i]->Value();
	}
	_jni->ReleaseDoubleArrayElements(aarray->_doubleArray, celems, mode->_int);
}

void  JavaRemote::JProcess::GetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, [OutAttribute] array<JBoolean^>^% buf) {
	jboolean* cbuf;
	_jni->GetBooleanArrayRegion(aarray->_booleanArray, start->_int, l->_int, cbuf);
	buf = gcnew array<JBoolean^>(l->_int - start->_int);
	for (int i = 0; i < (l->_int - start->_int); i++) {
		buf[i] = gcnew JBoolean(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JByte^>^% buf) {
	jbyte* cbuf;
	_jni->GetByteArrayRegion(aarray->_byteArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JByte^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JByte(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf) {
	jchar* cbuf;
	_jni->GetCharArrayRegion(aarray->_charArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JChar^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JChar(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JShort^>^% buf) {
	jshort* cbuf;
	_jni->GetShortArrayRegion(aarray->_shortArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JShort^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JShort(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JInt^>^% buf) {
	jint* cbuf;
	_jni->GetIntArrayRegion(aarray->_intArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JInt^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JInt(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JLong^>^% buf) {
	jlong* cbuf;
	_jni->GetLongArrayRegion(aarray->_longArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JLong^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JLong(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JFloat^>^% buf) {
	jfloat* cbuf;
	_jni->GetFloatArrayRegion(aarray->_floatArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JFloat^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JFloat(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, [OutAttribute] array<JDouble^>^% buf) {
	jdouble* cbuf;
	_jni->GetDoubleArrayRegion(aarray->_doubleArray, start->_int, len->_int, cbuf);
	buf = gcnew array<JDouble^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JDouble(cbuf[i]);
	}
}

void  JavaRemote::JProcess::SetBooleanArrayRegion(JBooleanArray^ aarray, JInt^ start, JInt^ l, array<JBoolean^>^ buf) {
	jboolean* cbuf = new jboolean[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->_boolean;
	}
	_jni->SetBooleanArrayRegion(aarray->_booleanArray, start->_int, l->_int, cbuf);
}
void  JavaRemote::JProcess::SetByteArrayRegion(JByteArray^ aarray, JInt^ start, JInt^ len, array<JByte^>^ buf) {
	jbyte* cbuf = new jbyte[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetByteArrayRegion(aarray->_byteArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetCharArrayRegion(JCharArray^ aarray, JInt^ start, JInt^ len, array<JChar^>^ buf) {
	jchar* cbuf = new jchar[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetCharArrayRegion(aarray->_charArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetShortArrayRegion(JShortArray^ aarray, JInt^ start, JInt^ len, array<JShort^>^ buf) {
	jshort* cbuf = new jshort[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetShortArrayRegion(aarray->_shortArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetIntArrayRegion(JIntArray^ aarray, JInt^ start, JInt^ len, array<JInt^>^ buf) {
	jint* cbuf = new jint[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetIntArrayRegion(aarray->_intArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetLongArrayRegion(JLongArray^ aarray, JInt^ start, JInt^ len, array<JLong^>^ buf) {
	jlong* cbuf = new jlong[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetLongArrayRegion(aarray->_longArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetFloatArrayRegion(JFloatArray^ aarray, JInt^ start, JInt^ len, array<JFloat^>^ buf) {
	jfloat* cbuf = new jfloat[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetFloatArrayRegion(aarray->_floatArray, start->_int, len->_int, cbuf);
}
void  JavaRemote::JProcess::SetDoubleArrayRegion(JDoubleArray^ aarray, JInt^ start, JInt^ len, array<JDouble^>^ buf) {
	jdouble* cbuf = new jdouble[buf->GetLength(0)];
	for (int i = 0; i < buf->GetLength(0); i++) {
		cbuf[i] = buf[i]->Value();
	}
	_jni->SetDoubleArrayRegion(aarray->_doubleArray, start->_int, len->_int, cbuf);
}

void  JavaRemote::JProcess::GetStringRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] array<JChar^>^% buf) {
	jchar* cbuf;
	_jni->GetStringRegion(str->_string, start->_int, len->_int, cbuf);
	buf = gcnew array<JChar^>(len->_int - start->_int);
	for (int i = 0; i < (len->_int - start->_int); i++) {
		buf[i] = gcnew JChar(cbuf[i]);
	}
}
void  JavaRemote::JProcess::GetStringUTFRegion(JString^ str, JInt^ start, JInt^ len, [OutAttribute] String^% buf) {
	char* cbuf;
	_jni->GetStringUTFRegion(str->_string, start->_int, len->_int, cbuf);
	buf = gcnew String(cbuf);
}

/*void *  JavaRemote::JProcess::GetPrimitiveArrayCritical(JArray^ array, [OutAttribute] JBoolean^% isCopy);
void  JavaRemote::JProcess::ReleasePrimitiveArrayCritical(JArray^ array, void *carray, JInt^ mode);

const array<JavaRemote::JChar^>^ JavaRemote::JProcess::GetStringCritical(JString^ string, [OutAttribute] JBoolean^% isCopy);
void  JavaRemote::JProcess::ReleaseStringCritical(JString^ string, String^ cstring);*/

JavaRemote::JBoolean^  JavaRemote::JProcess::ExceptionCheck() {
	return gcnew JBoolean(_jni->ExceptionCheck());
}

/*JavaRemote::JObject^  JavaRemote::JProcess::NewDirectByteBuffer(JNIEnv* env, void* address, JLong^ capacity);
void*   JavaRemote::JProcess::GetDirectBufferAddress(JNIEnv* env, JObject^ buf);
JavaRemote::JLong^  JavaRemote::JProcess::GetDirectBufferCapacity(JNIEnv* env, JObject^ buf);*/

IntPtr JavaRemote::JProcess::GetVMPointer() {
	return IntPtr(_jni->_VM);
}

IntPtr JavaRemote::JProcess::GetENVPointer() {
	return IntPtr(_jni->_ENV);
}

bool JavaRemote::JProcess::Attach(Process^ p, [OutAttribute] JProcess^% jp) {
	for each(ProcessModule^ mod in p->Modules)
	{
		if (mod->FileName->Contains("jvm.dll"))
		{
			jp = gcnew JProcess(p->Id);
			return true;
		}
	}
	return false;
}