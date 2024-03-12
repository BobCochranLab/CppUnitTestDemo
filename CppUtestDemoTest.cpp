#include "CppUtestDemo.h"

//CppUTest includes should be after your system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(CppUtestDemo)
{
  CppUtestDemo* cppUtestDemo;

  void setup()
  {
    cppUtestDemo = new CppUtestDemo();
  }
  void teardown()
  {
    delete cppUtestDemo;
  }
};

TEST(CppUtestDemo, Create)
{
  CHECK(true);
  CHECK_EQUAL(1,1);
  LONGS_EQUAL(1,1);
  DOUBLES_EQUAL(1.000, 1.001, .01);
  STRCMP_EQUAL("hello", "hello");
  FAIL("This is an unconditional FAIL.");
}

