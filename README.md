# CppUnitTestDemo

This repository is intended to help software engineers quickly see how to combine a C++ unit test infrastructure, a debugging setup, and flexibility to build and debug at either the linux command or from within VS Code.

If you are developing under Windows Subsystem for Linux (WSL), you should be able to clone this repository and soon be building, running and debugging the example code that combines a simple program with unit tests.

The Makefile comments explain some of the issues you might encounter.  So please read the Makefile!

The goals for this example are:
1)  To show how to create unit test code for your project's source code.
2)  To be able to build and debug Cpputest projects, both with 'make' and gdb at the linux command line, and with VS Code.
3)  To provide the following setup files for the .vscode directory so you can quickly be able to build, execute and debug inside VS Code on linux:
      - Makefile
      - launch.json
      - settings.json
      - tasks.json
