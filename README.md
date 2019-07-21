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
  JNI env;
  if (!JNI.AttachVM(targetProcess, out env) { 
    return; //Process is not a Java process (does not have the jvm module loaded).
  }

  JClass clazz = env.FindClass("fully/qualified/Name");
  JMethodID methodID = env.GetStaticMethodID(clazz, "isThisAFunction", "(IZ)Z"); 
  JBoolean boolean = env.CallStaticBooleanMethod(clazz, methodID, new JInt(54), new JBoolean(true));

  Console.WriteLine(boolean.Value());
  
  env.Dispose();
}
```
