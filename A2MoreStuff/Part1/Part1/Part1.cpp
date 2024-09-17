#include <iostream>

using namespace std;

void functionOneFirstHalf() {
    int a, b, c, d;
    a = 3;
    b = a++ + ++a;
    c = a++ + ++b;
    cout << a << b << c << endl; 
}

void functionOneSecondHalf() {
    int a, b, c;
    a = 5;
    b = 7;
    c = a + 4 < b;
    cout << a << b << c << endl;
}

void functionTwo() {
    int a, b, c, d;
    a = 5;
    b = 2;
    c = a < b;
    cout << c << endl;
    c = a < b + 4;
    cout << c << endl;
    d = a < b++;
    cout << a << b << c << d << endl;
    c = a + b++ + c++;
    d = ++a + b++ + ++c;
    cout << a << b << c << d << endl;
}

void functionThree() {
    int a, b, * p, * q, * r;
    a = 3;
    b = 6;
    p = &b;
    q = &a;
    *p = *q + 3;
    r = p;
    p = q;
    q = r;
    cout << a << b << *p << *q << *r << endl;
}

void functionFour() {
    int a, b = 7;
    int* p, * q, ** r, *** s;
    s = &r;
    r = &q;
    p = &a;
    r = &p;
    a = 5;
    q = &b;
    **r = *p - 6; 
    cout << a << b << *p << *q << **r << ***s << endl;
}


int main()
{
    functionOneFirstHalf();
    cout << endl;
    functionOneSecondHalf();
    cout << endl;
    functionTwo();
    cout << endl;
    functionThree();
    cout << endl;
    functionFour();
}
