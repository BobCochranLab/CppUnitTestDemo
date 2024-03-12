//
// g++ HelloWorld.cpp -- produces default-named executable file a.exe
// g++ HelloWorld.cpp -o HelloWorld.exe -- produces executable file HelloWorld.exe
// g++ -S HelloWorld.cpp -S -o HellWorld.asm -- produces assembly file HelloWorld.asm

#include <cstring>
#include <iostream>
using namespace std;
 
// Custom string class
class StringClass {
 
private:
   // Declare the char array
   char* str;
 
public:
 
   // Constructor with 1 argument
   StringClass(char* val);

   // Print member function
   void PrintString(void); 
};
 

// Function to illustrate Constructor
// with one argument
StringClass::StringClass(char* val)
{
   if (val == NULL) {
      str = new char[1];
      str[0] = '\0';
   }
   else {
      str = new char[strlen(val) + 1];
 
      // Copy character of val[]
      // using strcpy
      strcpy(str, val);
      str[strlen(val)] = '\0';
 
      cout << "The string passed for instantiation is: "
           << str << endl;
   }
}

void StringClass::PrintString(void)
{
   cout << str << endl;
}

// Driver Code
int main()
{
   // Declare and intialize a string.
   char theString[] = "Hello World!";
 
   // Constructor with one argument
   StringClass aStringObject(theString);

   aStringObject.PrintString();

   return 0;
}