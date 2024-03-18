# CppUnitTestDemo

This repository is intended to help software engineers quickly see how to combine a simple C++ program with a unit test infrastructure, a debugging setup, and flexibility to build/execute/debug at either the linux command line or from within VS Code.

The goals for this example are:
1)  To show how to create unit test code for your project's source code.
2)  To provide a setup that lets you build and debug this and other Cpputest projects, both with 'make' and gdb at the linux command line, and with VS Code.
3)  To provide the following setup files so you can quickly be able to build, execute and debug inside VS Code on linux (see these files under the .vscode directory):
      - Makefile
      - launch.json
      - settings.json
      - tasks.json

If you are developing under Windows Subsystem for Linux (WSL), you should be able to clone this repository and soon be building, running and debugging the example code that combines a simple program with unit tests.

The Makefile comments explain some of the issues you might encounter.  So please read the Makefile!

The first thing you will likely wonder when reading the Makefile is, "where is CPPUTEST_HOME?"  Good question!  You will need to install the unit testing framework and then point CPPUTEST_HOME to where you installed the framework.  The framework we use here is called CppUTest.

To install and use CppUTest on linux, you can use the web site's instructions for installing it.  It is available for public download, available here: https://cpputest.github.io/

Afer you install CppUTest, you will want to define CPPUTEST_HOME in your ~/.bashrc file.

The line you will add should look like something this (make sure the path is where you installed the cpputest framework):
      export CPPUTEST_HOME=/home/<username>/cpputest

Don't forget to run 'source ~/.bashrc' after adding the new definition for CPPUTEST_HOME.

Now you can run 'env | grep -i cpp' at the linux command line and see that CPPUTEST_HOME is defined.  You should get a line of output that looks like this:
      CPPUTEST_HOME=/home/bob/cpputest

