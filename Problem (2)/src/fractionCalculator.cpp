#include "fractionCalculator.h"

#include <bits/stdc++.h>
using namespace std;
fractionCalculator::fractionCalculator()
{

}
//the menu which will display to the user to choose the operation
void fractionCalculator::menue()
{
    cout <<"Welcome to fraction calculator"<<endl;

    fraction f1,f2;
    bool e=true;
    int n;
     vector<fraction> vect;

    while(e)
    {
        cout<< endl<<"1)adding "<<endl;
        cout<<"2)subtraction"<<endl;
        cout<<"3)multiplication"<<endl;
        cout<<"4)dividing"<<endl;
        cout<<"5)reduce"<<endl;
        cout<<"6)view previous results"<<endl;
        cout<<"7)compare"<<endl;
        cout<<"0)Exit"<<endl;

         cout<<"please enter number of operation"<<endl;
        cin >> n;
        //if the user chooses number 1 the calculator will add two fractions
        if(n==1)
        {
        cout <<"please enter your fractions "<<endl;
        cout<<"first fraction: ";
        cin>>f1;
        cout <<"second fraction: ";
        cin>>f2;
            fraction f3=f1+f2;
             vect.push_back(f3);

            cout << "f1+f2 = " << f3 <<" which is equal to: "<<f3.reduce()<< endl;
        }
        //if the user chooses number 2 the calculator will subtract two fractions
         if(n==2)
        {
            cout <<"please enter your fractions "<<endl;
        cout<<"first fraction: ";
        cin>>f1;
        cout <<"second fraction: ";
        cin>>f2;
            fraction f3=f1-f2;
             vect.push_back(f3);

            cout << "f1-f2 = " << f3 <<" which is equal to: "<<f3.reduce()<< endl;
        }
        //if the user chooses number 3 the calculator will multiply two fractions
         if(n==3)
        {
             cout <<"please enter your fractions "<<endl;
            cout<<"first fraction: ";
            cin>>f1;
            cout <<"second fraction: ";
            cin>>f2;
            fraction f3=f1*f2;
             vect.push_back(f3);

            cout << "f1*f2 = " << f3 <<" which is equal to: "<<f3.reduce()<< endl;
        }
        //if the user chooses number 4 the calculator will divide two fractions
         if(n==4)
        {
            cout <<"please enter your fractions "<<endl;
            cout<<"first fraction: ";
            cin>>f1;
            cout <<"second fraction: ";
            cin>>f2;
            fraction f3=f1/f2;
             vect.push_back(f3);

            cout << "f1/f2 = " << f3 <<" which is equal to: "<<f3.reduce()<< endl;
        }
        //if the user chooses number 5 the calculator will reduce the fraction
        if(n==5)
        {
             cout <<"please enter the fraction"<<endl;
            cin>>f1;
             vect.push_back(f1.reduce());

           cout<< "the reduced fraction: "<<f1.reduce()<<endl;
        }
        //if the user chooses number 6 the calculator will display the results of all operation done before
        if (n==6)
        {
             for (int i=0;i<vect.size();i++)
            {

                cout <<"result of operation no."<<i+1<<" is: "<<vect[i]<<endl;
            }
        }
        //if the user chooses number 7 the calculator will compare between to fractions
        if (n==7)
        {
            int choice;
            cout <<"please enter your fractions "<<endl;
            cout<<"first fraction: ";
            cin>>f1;
            cout<<"choose 1 for is greater than"<<endl;
            cout<<"choose 2 for is smaller than"<<endl;
            cout<<"choose 3 for is equal"<<endl;
            cout<<"choose 4 for is greater than or equal"<<endl;
            cout<<"choose 5 for is smaller than or equal"<<endl;
            //the user will choose how to compare between the two fractions
            cout<<"Enter your choise: ";
             cin>>choice;
            cout <<"second fraction: ";
            cin>>f2;
            if(choice==1)
            {
                if(f1>f2)
                    cout<<f1<<" is greater than "<<f2<<endl;
                else
                      cout<<f1<<" is not greater than "<<f2<<endl;
            }
            else if(choice==2)
            {
                if(f1<f2)
                    cout<<f1<<" is smaller than "<<f2<<endl;
                else
                      cout<<f1<<" is not smaller than "<<f2<<endl;
            }
            else if(choice==3)
            {
                if(f1.reduce() ==f2.reduce())
                    cout<<f1<<" is equal to "<<f2<<endl;
                else
                      cout<<f1<<" is not equal to "<<f2<<endl;
            }
           else if(choice==4)
            {
                if(f1>=f2)
                    cout<<f1<<" is greater than or equal "<<f2<<endl;
                else
                      cout<<f1<<" is not greater than or equal "<<f2<<endl;
            }
            else if(choice==5)
            {
                if(f1<=f2)
                    cout<<f1<<" is smaller than or equal "<<f2<<endl;
                else
                      cout<<f1<<" is not smaller than or equal "<<f2<<endl;
            }

        }
        if (n==0)
        {
            e=false;
        }


    }

}

