CC=/usr/bin/g++
DEBUG=-g -DDEBUG
CPPFLAGS += -I$(CPPUTEST_HOME)/include
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

all: HelloWorld CppUtestDemoTestRunner CppUtestDemoMono

default: HelloWorld CppUtestDemoTestRunner CppUtestDemoMono

assy: HelloWorld.s

HelloWorld.o: HelloWorld.cpp
	$(CC) -c HelloWorld.cpp -o HelloWorld.o

HelloWorld: HelloWorld.o
	$(CC) HelloWorld.o -o HelloWorld

HelloWorld.s: HelloWorld.cpp
	$(CC) -S HelloWorld.cpp -S -o HelloWorld.s

# This one doesn't need $(CPPFLAGS) because it doesn't include any .h files
# in the CppUTest include subdirectory, but I have it for consistency.
#
CppUtestDemo.o: CppUtestDemo.cpp
	$(CC) $(DEBUG) $(CPPFLAGS) -c CppUtestDemo.cpp -o CppUtestDemo.o

# Don't know why but my work Linux make doesn't need $(CPPFLAGS) for compiling the cpp files.
# Here on my personal Windows Subsystem for Linux, I get errors like the following if I
# don't have $(CPPFLAGS)
#
# CppUtestDemoTest.cpp:4:10: fatal error: CppUTest/TestHarness.h: No such file or directory
#     4 | #include "CppUTest/TestHarness.h"
#
CppUtestDemoTest.o: CppUtestDemoTest.cpp
	$(CC) $(DEBUG) $(CPPFLAGS) -c CppUtestDemoTest.cpp -o CppUtestDemoTest.o

CppUtestDemoTestRunner.o: CppUtestDemoTestRunner.cpp
	$(CC) $(DEBUG)  $(CPPFLAGS) -c CppUtestDemoTestRunner.cpp -o CppUtestDemoTestRunner.o

# The script-generated three-file executable does not work with the VS Code built-in debugger,
# but it runs under gdb.
#
# The error is:
# 	/usr/bin/ld: /tmp/ccNPkxdS.o:(.data.rel+0x0): undefined reference to `externTestGroupCppUtestDemo'
# 	collect2: error: ld returned 1 exit status
#
CppUtestDemoTestRunner: CppUtestDemo.o CppUtestDemoTest.o CppUtestDemoTestRunner.o
	$(CC) $(DEBUG) CppUtestDemo.o CppUtestDemoTest.o CppUtestDemoTestRunner.o $(LD_LIBRARIES) -o CppUtestDemoTestRunner

CppUtestDemoMono.o: CppUtestDemoMono.cpp
	$(CC) $(DEBUG) $(CPPFLAGS) -c CppUtestDemoMono.cpp -o CppUtestDemoMono.o

# Putting everything from the script-generated three files into one cpp file gives us an exectuable
# that runs under the VS Code built-in debugger.
#
CppUtestDemoMono: CppUtestDemoMono.o
	$(CC) $(DEBUG) CppUtestDemoMono.o $(LD_LIBRARIES) -o CppUtestDemoMono

clean:
	rm -f HelloWorld.o
	rm -f HelloWorld
	rm -f CppUtestDemo.o
	rm -f CppUtestDemoTest.o
	rm -f CppUtestDemoTestRunner.o
	rm -f CppUtestDemoTestRunner
	rm -f CppUtestDemoMono.o
	rm -f CppUtestDemoMono