# JNetRemote
.NET library for interfacing with java processes (C++/CLI). 

## Features
 - Fully external. Loads no native or Java bytecode into the target process.
 - Same code format as the JNI C API, but .NET-ified.
 - Written in C++ as a CLI library.

## Usage

```c#
static void Main(string[] args) 
{
  Process targetProcess = Processes.GetProcessesByName("javaw")[0];
  JProcess jni;
  if (!JProcess.Attach(targetProcess, out jni) { 
    return; //Process is not a Java process (does not have the jvm module loaded).
  }

  JClass clazz = jni.FindClass("fully/qualified/Name");
  JMethodID methodID = jni.GetStaticMethodID(clazz, "isThisAFunction", "(IZ)Z"); 
  JBoolean boolean = jni.CallStaticBooleanMethod(clazz, methodID, new JInt(54), new JBoolean(true));

  Console.WriteLine(boolean.Value());
  
  jni.Dispose();
}
```
