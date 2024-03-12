#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

const int   expectedInt   =   1;
const long  expectedLong  = 100;
const float expectedFloat = 123.321;

//
// Class declaration
//
class CppUTestRoman
  {
  public:
    explicit CppUTestRoman();
    virtual ~CppUTestRoman();

    const int   getInt(void);
    const long  getLong(void);
    const float getFloat(void);

  private:

    CppUTestRoman(const CppUTestRoman&);
    CppUTestRoman& operator=(const CppUTestRoman&);

    int   Integer;
    long  Long;
    float Float;
  };

//
// Class member function implementations
//
CppUTestRoman::CppUTestRoman()
{
}

CppUTestRoman::~CppUTestRoman()
{
}

const int CppUTestRoman::getInt(void)
{
    return 1;
}

const long CppUTestRoman::getLong(void)
{
    return 100;
}

const float CppUTestRoman::getFloat(void)
{
    return 123.321;
}

//
// CppUtest TEST_GROUP and TEST
//
TEST_GROUP(CppUTestRoman)
{
  CppUTestRoman* cppUTestRoman;

  void setup()
  {
    cppUTestRoman = new CppUTestRoman();
  }
  void teardown()
  {
    delete cppUTestRoman;
  }
};

TEST(CppUTestRoman, Create)
{
    // Instantiate a CppUtest object.
    CppUTestRoman testObject;

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

IMPORT_TEST_GROUP(CppUTestRoman);