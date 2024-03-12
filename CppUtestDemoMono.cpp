#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
/*
Imaginary Requirements in an imaginary Specification:

I.   A member function of class CppUtestDemo with a return type of int shall return the value 1.
II.  A member function of class CppUtestDemo with a return type of long shall return the value 100.
III. A member function of class CppUtestDemo with a return type of float shall return the value 123.321.

Therefore, we define the following expected typed values:
*/
const int   expectedInt   =   1;
const long  expectedLong  = 100;
const float expectedFloat = 123.321;

//
// Class declaration
//
class CppUtestDemo
  {
  public:
    explicit CppUtestDemo();
    virtual ~CppUtestDemo();

    const int   getInt(void);
    const long  getLong(void);
    const float getFloat(void);

  private:

    CppUtestDemo(const CppUtestDemo&);
    CppUtestDemo& operator=(const CppUtestDemo&);

    int   Integer;
    long  Long;
    float Float;
  };

//
// Class member function implementations
//
CppUtestDemo::CppUtestDemo()
{
}

CppUtestDemo::~CppUtestDemo()
{
}

const int CppUtestDemo::getInt(void)
{
    return 1;
}

const long CppUtestDemo::getLong(void)
{
    return 100;
}

const float CppUtestDemo::getFloat(void)
{
    return 123.321;
}

//
// CppUtest TEST_GROUP and TEST
//
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
    // Instantiate a CppUtest object.
    CppUtestDemo testObject;

    // Trying out macros defined in /usr/include/CppUTest/UtestMacros.h
    CHECK(true);
    CHECK_EQUAL(1,1);
    LONGS_EQUAL(1,1);
    DOUBLES_EQUAL(1.000, 1.001, .01);
    STRCMP_EQUAL("hello", "hello");
    //FAIL("This is an unconditional FAIL.");

    // Trying out the same macros for testing our functions
    CHECK_EQUAL(expectedInt,   testObject.getInt());
    CHECK_EQUAL(expectedLong,  testObject.getLong());
    CHECK_EQUAL(expectedFloat, testObject.getFloat());
}

//
// main function that would typically be in a runner .c/.cpp file
//
int main(int ac, char** av)
{
  return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(CppUtestDemo);