The examples are

# Minimal Executable
This is to use a minimal setup to show how cmake works.

/root
  ├── CMakeLists.txt
  └── main.cpp

There is only one file in the project.
So there is only one cmake file.

# Flat Structure
This setup is to show how cmake handles self-contained source code in a flat project structure. This is the simplest project structure.

/root
  ├── CMakeLists.txt
  ├── util.h
  ├── util.cpp
  └── main.cpp

The main has only one dependency (util files) which has no external dependencies.
So there is only one cmake file.

# Subdirectory Structure
This setup is to show how cmake handles self-contained source code with subfolders.
This is a more common project structure in a simplied manner.

/root
  ├── /helper
  |     ├── util.h
  |     ├── util.cpp
  |     ├── CMakeLists.txt
  ├── /math
  |     ├── arithmetic.h
  |     ├── arithmetic.cpp
  |     ├── CMakeLists.txt
  ├── CMakeLists.txt
  └── main.cpp

There are 2 subfolders, with each contains some files and a cmake file.
The main program depends on the subfolder's code. But the subfolders' code has no external dependencies.
The executable has no dependencies either since the subfolders' codes were added directly into the main code.

# Internal Library
This setup is to show how cmake creates static/dynamic libraries and how to link the libraries to the other code (in this case executable code).
The project structure is the same as in Subdirectory Structure section.

So to run the executable, we need the dynamic library files.Otherwise, it will give link errors.

# Precompiled Library
Sometimes, we are only given the compiled files of static/dynamic libraries (binary).
This is to show how to integrate those libraries and use them in our projects.

/root
  ├── /external
  |     ├── /include
  |     |       ├── util.h
  |     |       ├── arithmetic.h
  |     ├── /lib
  |     |       ├── libutil.so
  |     |       ├── libarithmetic.a
  |     ├── CMakeLists.txt
  ├── CMakeLists.txt
  └── main.cpp

# Header Only
For header only source libraries, CMake provide convenient ways to include them.

/root
  ├── /helper
  |     ├── util.h
  |     ├── CMakeLists.txt
  ├── /math
  |     ├── arithmetic.h
  |     ├── CMakeLists.txt
  ├── CMakeLists.txt
  └── main.cpp

# Library Source
A lot of open source projects are available for use. One way to include them is to add them as submodules that we can trace the version to use.
So we have to download the project source first.
Those project provide normally a CMake file that we can just include into our project.
We take SOIL2 and lua as example here.

# Fetch Library Source
Instead of downloading manually, CMake provides some commands to do the download automatically with the library url and the version tag.

# Manage Library Conan
Similar to pip, conan intends to fill the void of package management for c++. So instead of downloading the source code, compiling, integrating by ourself, Conan manage all for us and we can just simply link to the library.

# Test
/root
  ├── /helper
  |     ├── util.h
  |     ├── util.cpp
  |     ├── CMakeLists.txt
  ├── /math
  |     ├── arithmetic.h
  |     ├── arithmetic.cpp
  |     ├── CMakeLists.txt
  ├── /tests
  |     ├── /unit
  |     |     ├── test_arithmetic.cpp
  |     |     ├── test_util.cpp
  |     ├── CMakeLists.txt
  ├── CMakeLists.txt
  └── main.cpp

To run the ctest tests:
```
$> cmake -D TEST_GOOGLE:BOOL=false ..
$> cmake --build .
$> ctest
```

To run the google tests:
```
$> cmake -D TEST_GOOGLE:BOOL=true ..
$> cmake --build .
$> ctest
```
