#include <bits/stdc++.h>
#include "fraction.h"

using namespace std;


//the parametrized constructor for the class fraction
fraction:: fraction(int n1, int n2)
    {

     num1=n1;
     num2=n2;


    }
//the operator overloading (+) that allow the user to add the fractions normally
fraction fraction:: operator +(const fraction&f2)
    {
        fraction f3;
        f3.num1=num1*f2.num2+f2.num1*num2;
        f3.num2=num2*f2.num2;

        return f3;
    }
    //the operator overloading (-) that allow the user to subtract the fractions normally
fraction fraction:: operator -(const fraction&f2)
    {
        fraction f3;
        f3.num1=num1*f2.num2-f2.num1*num2;
        f3.num2=num2*f2.num2;

        return f3;
    }
//the operator overloading (*) that allow the user to multiply the fractions normally
fraction fraction:: operator *(const fraction&f2)
    {
        fraction f3;
        f3.num1=num1*f2.num1;
        f3.num2=num2*f2.num2;

        return f3;
    }
//the operator overloading (/) that allow the user to devide the fractions normally
fraction fraction:: operator /(const fraction&f2)
    {
        fraction f3;
        f3.num1=num1*f2.num2;
        f3.num2=num2*f2.num1;

        return f3;
    }
//the operator overloading (>) which check if a fraction is greater than another faraction
bool fraction:: operator>(const fraction & f)
    {
        bool status;

        if (((float)num1/num2)>((float)f.num1/f.num2))
        {
            status=true;
        }
        else
        {
            status =false;
        }
        return status;
    }

//the operator overloading (<) which check if a fraction is smaller than another faraction
bool fraction:: operator <(const fraction & f)
    {
        bool status;
        if (((float)num1/num2)<((float)f.num1/f.num2))
            status=true;
        else
            status =false;
        return status;
    }

//the operator overloading (==) which check if a fraction is equal another faraction
bool fraction::   operator ==(const fraction & f)
    {
        bool status;

        if (((float)num1/num2)==((float)f.num1/f.num2))
            status=true;
        else
            status =false;

        return status;
    }

//the operator overloading (>=) which check if a fraction is greater than or equal another faraction
 bool fraction::operator >=(const fraction & f)
    {
        bool status;
        if (((float)num1/num2)==((float)f.num1/f.num2) || ((float)num1/num2)>((float)f.num1/f.num2))
            status=true;
        else
            status =false;
        return status;
    }

//the operator overloading (<=) which check if a fraction is smaller than or equal another faraction
 bool fraction:: operator <=(const fraction & f)
    {
        bool status;
        if (((float)num1/num2)==((float)f.num1/f.num2) || ((float)num1/num2)<((float)f.num1/f.num2) )
            status=true;
        else
            status =false;
        return status;
    }
//function which reduce the fraction to its simplest form
fraction fraction:: reduce ()
    {
        fraction rf;
        int mini;
        if(num1<num2)
        {
            mini=num1;
        }
        else
        {
            mini = num2;
        }
        for(int i=mini;i>0;i--)
        {
            if(num1%i==0 && num2%i==0)
            {
                rf.num1=num1/i;
                rf.num2=num2/i;
                break;

            }
        }
        return rf;

    }
//operator overloading(>>) to cin the fraction normally
istream& operator>>(istream& is, fraction &f)
    {
        is>>f.num1>>f.x>>f.num2;
         while (f.num2==0)
        {
         cout<<"you can not divide by zero , please try again"<<endl;
         is>>f.num1>>f.x>>f.num2;

        }

        return is;
    }
    //operator overloading(<<) to cout the fraction normally
ostream& operator<<(ostream& is, const fraction& f)
    {
        is<< f.num1 <<'/'<<f.num2;
        return is;
    }
