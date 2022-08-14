#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;


class fraction
{
private:
    int num1;
    char x;
    int num2;
public:
    fraction(int n1=0,int n2=0);
    fraction operator +(const fraction&f2);
    fraction operator -(const fraction&f2);
    fraction operator *(const fraction&f2);
    fraction operator /(const fraction&f2);
    bool operator>(const fraction & f);
    bool operator <(const fraction & f);
    bool operator ==(const fraction & f);
    bool operator >=(const fraction & f);
    bool operator <=(const fraction & f);
    fraction reduce ();
    friend istream& operator>>(istream& is, fraction &f);
    friend ostream& operator<<(ostream& is, const fraction& f);
};

#endif // FRACTION_H
