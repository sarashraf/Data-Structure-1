//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178


#include <bits/stdc++.h>

using namespace std;

// class phone directory which contains firstname,lastname and phone number of each object
class phoneDirectory
{
private:
    string f_name;
    string l_name;
    string phone_no;
public:
    // default constructor
    phoneDirectory()
    {

    }
    //paramertized constructor which takes firstname,lastname and phone number as arguments
    phoneDirectory(string fn,string ln,string pn)
    {
        f_name=fn;
        l_name=ln;
        phone_no=pn;
    }
    //copy constructor
    phoneDirectory(const phoneDirectory &obj)
    {
        f_name=obj.f_name;
        l_name=obj.l_name;
        phone_no=obj.phone_no;
    }

    // an overloading cin operator to cin the object directly through it
    friend istream& operator>>(istream& is, phoneDirectory & pd )
    {
        cout<< "enter first name: ";
        is>>pd.f_name;
        cout<<endl <<"enter second name: ";
        is >>pd.l_name;
        cout <<endl<<"enter the phone number: ";
        is >>pd.phone_no;
            return is;
    }
    // an overloading cout operator to cout the object directly through it
    friend ostream& operator<<(ostream& os, const phoneDirectory & pd)
    {
        os<<"first name: " <<pd.f_name<<endl<<"last name: "<<pd.l_name<<endl<<"phone no.: "<<pd.phone_no<<endl;
        return os;
    }
    // sorting the vector which contain the phone directories with insertion sort algorthim
    void insertionSort(vector <phoneDirectory> & pd)
    {

        int j;
        string tmp;
        phoneDirectory key;
        for (int i = 1; i < pd.size(); i++)
        {
            key= pd[i];
            tmp=pd[i].f_name;
            j = i - 1;

            while (j >= 0 && pd[j].f_name > tmp)
            {
                pd[j + 1]=pd[j];
                j = j - 1;
            }
            pd[j + 1] =key;
        }
    }
    // sorting the vector which contain the phone directories with selection sort algorthim
    void selectionSort(vector <phoneDirectory> & pd)
    {
        int minIdx;

        for (int i = 0; i < pd.size() - 1; i++)
        {
            minIdx = i;

            for (int j = i + 1; j < pd.size(); j++)
                if (pd[j].f_name< pd[minIdx].f_name)
                    minIdx = j;
                    swap(pd[minIdx], pd[i]);

        }
    }

    // sorting the vector which contain the phone directories with bubble sort algorthim
    void bubbleSort(vector <phoneDirectory> & pd)
    {
        bool flag = true;

        for (int i = 0; i < pd.size() - 1; i++)
        {
            for (int j = 0; j < pd.size()- i - 1; j++)
            {
                if (pd[j].f_name > pd[j + 1].f_name)
                {
                    swap(pd[j], pd[j + 1]);
                    flag = false;
                }

            }
            if (flag == true)
                break;

        }

    }

    //  a search function to search for the phone directory entry using the first name
    phoneDirectory searchByFname(vector<phoneDirectory> & pd,string fn)
    {

        for(int i=0;i<pd.size();i++)
        {
            if (fn==pd[i].f_name)
            {
                return pd[i];
                break;
            }
        }
    }

     //  a search function to search for the phone directory entry using the phone number
     phoneDirectory searchByPhone(vector<phoneDirectory> & pd,string pn)
    {

        for(int i=0;i<pd.size();i++)
        {
            if (pn==pd[i].phone_no)
            {
                return pd[i];
                break;
            }
        }
    }

    // a delete function which will delete the whole data of that phone directory entry through the first name
     void deleteByFname(vector<phoneDirectory> & pd,string fn)
    {
        phoneDirectory entry;
        entry.insertionSort(pd);
        //entry.bubbleSort(directory);
        //enrty.selectionSort(directory);



        for(int i=0;i<= pd.size();i++)
        {
            for (int j=0;j<pd.size();j++)
            {
                 if (fn==pd[j].f_name)
                {

                    pd.erase(pd.begin()+j);

                }
            }

        }
    }





};

int main()
{
    phoneDirectory p1;

    // creating a vector which will contain the phone directory entires
    vector<phoneDirectory> directory;

    bool e=true;
    while  (e)
    {
        // displaying the menu for the user to choose the operation
        cout<<endl;
        cout<< "1. Add an entry to the directory"<<endl;
        cout<< "2. Look up a phone number"<<endl;
        cout<< "3. Look up by first name"<<endl;
        cout<< "4. Delete an entry from the directory"<<endl;
        cout<< "5. List All entries in phone directory"<<endl;
        cout<< "6. Exit form this program"<<endl;
        int choice;
        cout<<endl<<"Please enter the number of the operation: ";
        cin>>choice;

        // will add an entry to the phone directory if chosen
        if(choice==1)
        {
             cin>>p1;
            directory.push_back(p1);
        }

        // will look up by the phone number in the stored phone directory if chosen
        if(choice ==2)
        {
            string phone;
            cout << "Enter the phone number: "<<endl;
            cin>>phone;
            cout<<p1.searchByPhone(directory,phone)<<endl;

        }

        // will look up by the first name in the stored phone directory if chosen
        if(choice==3)
        {
            string name;
            cout << "Enter the name: "<<endl;
            cin>>name;
            cout<<p1.searchByFname(directory,name)<<endl;
        }

         // will delete an entry by first name from the stored phone directory if chosen
        if(choice ==4)
        {
            string name;
            cout << "Enter the name: ";
            cin>>name;

            p1.deleteByFname(directory,name);
            cout <<"The entry has been deleted successfully"<<endl;
        }

        // will list all the entries stored in the phone directory in an alphabetical order by first name if chosen
        if(choice==5)
        {
          p1.insertionSort(directory);
            // p1.selectionSort(directory);
            // p1.bubbleSort(directory);

            for(int i =0;i<directory.size();i++)
            {
                cout<<"The entry number "<<i+1<<": "<<endl<<directory[i]<<endl;
            }
            if (directory.size()==0)
            {
                cout<<"The list is empty"<<endl;
            }
        }

        // will exit from the program if chosen
        if(choice==6)
        {
            e=false;
        }

    }


    return 0;
}

