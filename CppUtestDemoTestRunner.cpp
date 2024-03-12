#include "CppUTest/CommandLineTestRunner.h"
#include "CppUtestDemo.h"

int main(int ac, char** av)
{
  int i = 0;

  i += 10;
  i += 100;
  i += 1000;

  return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(CppUtestDemo);