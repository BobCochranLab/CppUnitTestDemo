# CppUnitTestDemo
Demo code for using Cpputest for C++ unit testing under linux.  The code here
runs under Windows Subsystem for Linux (WSL).

The Makefile comments explain some of the issues you might encounter.

The goals for this example are:
1)  To show how to create unit test code for your project's source code.
2)  To be able to build and debug Cpputest projects, both with 'make' and gdb at the linux command line, and with VS Code.
3)  To provide the following setup files for the .vscode directory so you can quickly be able to build, execute and debug inside VS Code on linux:
      - Makefile
      - launch.json
      - settings.json
      - tasks.json
