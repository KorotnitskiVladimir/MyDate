#include "MyDate.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    MyDate d1(2024, 6, 8);
    MyDate d2 = d1-8;
    d2.print();
    d2-=31;
    d2.print();
    d2+=32;
    d2.print();
    MyDate d3 = d2;
    ++d3;
    d3.print();
    cout << (d2>=d3) << endl;
        
    return 0;
}
