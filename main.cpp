#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/any.hpp>

using namespace std;
using namespace boost;

/*
 * 
 */
int main(int argc, char** argv) {
    
    any variable;
    any integer { 7 };
    any doubleNumber { 7.5 };
    any strText = string("whatever");
    vector<any> container { "lifeIsSuch", 32, "notReally", 90.233 };
    
    if (variable.empty())
        cout << variable.type().name() << endl; //just to check what is returned for an uninitialized variable
    
    if (!integer.empty())
        cout << integer.type().name() << endl; //just returns the starting letter of a type
    
    try { /*Surround in try catch to check for bad casting*/
        cout << "The value of integer is " << any_cast<int>(integer) << endl;
        cout << "The value of double is " << any_cast<double>(doubleNumber) << endl;
        cout << "The value of string is '" << any_cast<string>(strText) << "'" << endl; 
    }
    catch(const bad_any_cast& e) { //just replace with wrong type to test exception
        cerr << "wrong type casted\n";
    }
    
    cout << "Outputting any vector:\n\n";
    /*Unless you specify the correct any_cast, the value will become a 
      nullptr so that's why you need to account for all variable types*/
    for (any i : container) {
        const char** strValue = any_cast<const char*>(&i);
        if (strValue != nullptr)
            cout << *strValue << endl;
        
        double* dblValue = any_cast<double>(&i);
        if (dblValue != nullptr)
            cout << *dblValue << endl;
        
        int* intValue = any_cast<int>(&i);
        if (intValue != nullptr)
            cout << *intValue << endl;
    }

    return 0;
}

