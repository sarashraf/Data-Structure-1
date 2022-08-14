//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178

#include <iostream>

using namespace std;
// class student which contains a name as an attribute
class StudentName
{
private:
    string name;
public:
    int numofspaces=0,lastone=0;

    // creating a dynamic string array
    string *arr;

// constructor which takes  a name as an argumment
    StudentName(string passedname)
    {
        // a for loop to check the number of spaces found int he name passed
        for (int i=0;i<passedname.length();i++)
        {
            if (passedname[i]==' ')
            {
               numofspaces++;
               lastone=i;

            }

        }
         // a condition in case there is no space found in the name
        if (numofspaces==0)
        {
            name=passedname+" "+passedname+" "+passedname;
            numofspaces=2;
        }
         // a condition in case there is only one space found in the name
        else if (numofspaces==1)
        {
            name=passedname+passedname.substr(lastone);
            numofspaces=2;
        }
        else
        // a condition in case there is more than or two space found in the name
        {
            name=passedname;
        }
        // forming the array which will contain each name separately in an index
        arr=new string [numofspaces+1];

    }

    // print function which will print the string after the modification done on it
    void print()
    {
        int n=0;
        // moving each character of a name to be stored as whole in a certain index in the string array
        for (int i=0;i<numofspaces+1;i++)
        {
            bool flag=true;
            for (int j=n;j<name.length();j++,n++)
            {
                if (name[n]!=' ' && flag==true)
                {
                    arr[i]+=name[n];

                }
                else if (name[n]==' ')
                {
                    flag=false;
                    n++;
                     break;

                }

            }

        }


      //printing out the string
      for (int i=0;i<numofspaces+1;i++)
      {

         cout<<i+1<<")"<<arr[i]<<endl;
      }

    }

    // a replace function which will return true in case we succeed in swaping the two names together according
    //to their indices and will return false otherwise
    bool replacee(int i,int j)
    {
        // checking whether the indices are within the range or not
        if (i>numofspaces+1 || j>numofspaces+1 || i<0 || j<0)
        {
            return false;
        }
        else
        {
            string temp;
            temp=arr[i-1];
            arr[i-1]=arr[j-1];
            arr[j-1]=temp;
            return true;
        }
    }

};

int main()
{
    /* creating objects of studentName and then checking whether
     we can replace between the two names or not , if we succeed in swaping
     between them (the function returned true), then the whole name will
     be printed after the modification done on ,it otherwise it will display
     an error message that the indices are out of range....
    */
    cout<<"Test 1:"<<endl;
    StudentName name1("ali ahmed salah");
    if (name1.replacee(1,3))  //if Index in the Range
    {
         name1.print();

    }
    else //if the Index Is Out Of Range
    {
        cout<<"Index Is Out Of Range"<<endl;
    }
    cout<<endl;


    cout<<"Test 2:"<<endl;
    StudentName name2 ("salma sameh");
    if (name2.replacee(1,2))
    {
         name2.print();

    }
    else
    {
        cout<<"Index Is Out Of Range"<<endl;
    }
    cout<<endl;


    cout<<"Test 3:"<<endl;
    StudentName name3 ("jana ahmed mohamed adel");
    if (name3.replacee(1,5))
    {
         name3.print();

    }
    else
    {
        cout<<"Index Is Out Of Range"<<endl;
    }
    cout<<endl;


    cout<<"Test 4:"<<endl;
    StudentName name4("samy");
    if (name4.replacee(1,3))
    {
         name4.print();

    }
    else
    {
        cout<<"Index Is Out Of Range"<<endl;
    }
    cout<<endl;


    cout<<"Test 5:"<<endl;
    StudentName name5("ali salah");
    if (name5.replacee(1,4))
    {
         name5.print();

    }
    else
    {
        cout<<"Index Is Out Of Range"<<endl;
    }





    return 0;
}
