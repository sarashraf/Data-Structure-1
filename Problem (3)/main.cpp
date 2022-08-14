
//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178

#include <iostream>
#include "matrix.h"

using namespace std;

class  MatrixCalculator
{
public:
    void menu();
};

//MatrixCalculator class which offers the user a menu of operations to perform on int matrices as follows
void MatrixCalculator:: menu()
{
    cout<<"--Welcome in our calculator--"<<endl<<endl;
    char c;
    while(true)
    {
        cout<<"Choose form this manu: "<<endl;
        cout<<"1- Perform Matrix Addition Enter(+)"<<endl;
        cout<<"2- Perform Matrix Subtraction Enter(-)"<<endl;
        cout<<"3- Perform Matrix Multiplication Enter(*)"<<endl;
        cout<<"4- Matrix Transpose Enter(T or t)"<<endl;
        cout<<"5- To close the program Enter(0)"<<endl;

        cin>>c;      //user choose the operation he need
        cout<<endl;

        //when he wants to exit the program
        if(c=='0')
        {
            break;  //Exit the program
        }

        //Perform Matrix Addition
        else if (c=='+')
        {
            Matrix<int> m1,m2;
            cout<<"first Matrix:"<<endl;
            cin>>m1;
            cout<<"second Matrix:"<<endl;
            cin>>m2;
            if(check(m1,m2))  //call function check to check the dimensions
            {
                Matrix<int>m3=m1+m2;    //if true the process will be done
                cout<<m3;
            }
            else              //if false the program will be closed
            {
                cout<<"Wrong dimensions please try again "<<endl;
                break;
            }
        }

        //Perform Matrix Subtraction
        else if (c=='-')
        {
            Matrix<int> m1,m2;
            cout<<endl<<"first Matrix:"<<endl;
            cin>>m1;
            cout<<endl<<"second Matrix:"<<endl;
            cin>>m2;
            if(check(m1,m2)) //call function check to check the dimensions
            {
                Matrix<int>m3=m1-m2;    //if true the process will be done
                cout<<m3;
            }
            else             //if false the program will be closed
            {
                cout<<"Wrong dimensions please try again"<<endl;
                break;
            }
        }

        //Perform Matrix Multiplication
        else if (c=='*')
        {
            Matrix<int> m1,m2;
            cout<<endl<<"first Matrix:"<<endl;
            cin>>m1;
            cout<<endl<<"second Matrix:"<<endl;
            cin>>m2;
            if(check_Mul(m1,m2))   //call function check to check the dimensions
            {
                Matrix<int>m3=m1*m2;        //if true the process will be done
                cout<<m3;
            }
            else                 //if false the program will be closed
            {
                cout<<"Wrong dimensions please try again"<<endl;
                break;
            }

        }

        //Matrix Transpose
        else if (c=='T' ||c=='t')
        {
            Matrix<int> m;
            cout<<endl<<"Matrix Transposed:"<<endl;
            cin>>m;
            cout<<m.Transpose();
        }
    }
}


int main()
{
    MatrixCalculator m;
    m.menu();

    return 0;
}
