//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class bigint
{
private:
    string num;
    int numint;
    int siz;

public:
    stack<int>number;
    stack<int>number2;
    stack<int>temp;
    int s_siz;

    //default constructor
    bigint()
    {
    }

    //constructor Initialize from string and rejects bad input
    bigint(string n)
    {
        //to reject the bad input if any index is not digit
        for(int i=0;i<n.length();i++)
        {
            if(!isdigit(n[i]) && n[i]!='-')
            {
                cout<<"the input is not integer and can not make your operation !"<<endl;
                exit(0);  // close the program
            }
        }
        num=n;
        siz=num.length();
        int x;
        //to know if your biginteger is negative
        if (check_neg(num))
        {
            for(int i=1;i<siz;i++) //if negative --> ignore the sign(-) ant push the anther digits
            {
                x=num[i]-'0';
                number.push(x);
            }
            for(int i=siz-1;i>0;i--)
            {
                x=num[i]-'0';
                temp.push(x);
            }
            temp.top()*=(-1);
        }
        else //if positive
        {
            for(int i=0;i<siz;i++)
            {
                x=num[i]-'0';
                number.push(x);
            }
            for(int i=siz-1;i>=0;i--)
            {
                x=num[i]-'0';
                temp.push(x);
            }
        }
        s_siz=number.size();

    }

    //Initialize from integer
    bigint(int in)
    {
        numint=in; //123
        while ((!in==0))
        {
            number2.push(in%10);
            in/=10;
        }
        while (!number2.empty())
        {
            number.push(number2.top());
            number2.pop();
        }
    }

    bigint operator=(const bigint & obj );
    bigint operator +(bigint & obj);
    bigint operator -(bigint & obj);
    friend ostream& operator << (ostream& os, bigint &obj);

    //boolean function to check the biginteger if negative or positive
    bool check_neg(string nn)
    {
        if (nn[0]=='-') //if negative return true
        {
            return true;
        }

        else            //if positive return false
        {
            return false;
        }
    }


    //to get the size of the string include the sign if it is negative
    int size()
    {
        return siz;
    }

    //to get the size of integers
    int gets_siz()
    {
        return s_siz;
    }

    //to get the string
    string getnum()
    {
        return num;
    }

};

//to copy the biginteger to another big integer
bigint bigint :: operator = (const bigint & obj )
{
    bigint res;
    res.num=obj.num;
    return res;
}

//overloading operator(+) to add two biginteger
bigint bigint :: operator + (bigint & obj2)
{
    bigint c(num);
    //bigint n(obj2.numint);
    bigint obj(obj2.num);
    int r,sz;

    if( !check_neg(num) && check_neg(obj.num) )  //if num1 is positive and num2 is negative
    {
        if(s_siz < obj.s_siz) //if num1 < num2 in number of digits the result will be negative
        {
            bigint res=obj-c;
            res.temp.top()*=(-1);
            return res;
        }
        else if(s_siz==obj.s_siz ) //if num1 < num2 without the sign the result will be negative
        {
            for(int i=0;i<s_siz;i++)
            {
                if(num[i]<obj.num[i+1])
                {
                    bigint res=obj-c;
                    res.temp.top()*=(-1);
                    return res;
                }
            }
            bigint res=c-obj; //if num1 > num2 the result will be positive
            return res;
        }
        else //if num1 > num2 the result will be positive
        {
            bigint res=c-obj;
            return  res;
        }

    }
    else if (!check_neg(obj.num) && check_neg(num))   //if num1 is negative and num2 is positive
    {
        if(s_siz > obj.s_siz )   //if num1 > num2 in number of digits the result will be negative
        {
            bigint res=c-obj;
            res.temp.top()*=(-1);
            return res;
        }
        else if(s_siz==obj.s_siz )  //if num1 > num2 without the sign the result will be negative
        {
            for(int i=0;i<s_siz;i++)
            {
                if(num[i+1] > obj.num[i])
                {
                    bigint res=c-obj;
                    res.temp.top()*=(-1);
                    return res;
                }
            }
            bigint res=obj-c;  //if num1 < num2 the result will be positive
            return res;
        }
        else                   //if num1 < num2 the result will be positive
        {
            bigint res=obj-c;
            return  res;
        }
    }
    else  //if num1 and num2 are both is positive or negative
    {
        bigint res;
        //to check if any biginteger greater than other in digit
        if(number.size() < obj.number.size())
        {
            sz=number.size();
        }
        else
        {
            sz=obj.number.size();
        }

        //loop until the smallest size
        for(int i=0;i<sz;i++)
        {
            r=number.top()+obj.number.top();
            if(r>=10)  //if the sum of two digit greater than or equal 10 so will be cary 1 for the next digit
            {
                r-=10;
                res.temp.push(r);
                number.pop();
                obj.number.pop();

                if(number.empty() && obj.number.empty()) //if both biginteger empty and we have cary
                {
                    res.temp.push(1);    //add digit to the result for the cary (1)
                }
                else if(!number.empty())
                {
                    number.top()+=1;  //add 1 to the biginteger1 for the cary if is not empty
                }
                else if(!obj.number.empty())  //add 1 to the biginteger2 for the cary if is the biginteger 1 is empty
                {
                    obj.number.top()+=1;
                }

            }
            else    //sum less than 10
            {
                res.temp.push(r);
                number.pop();
                obj.number.pop();
            }

        }
        //if any biginteger is not empty
        while (!number.empty() || !obj.number.empty())
        {
            if(number.empty())
            {
                res.temp.push(obj.number.top());
                obj.number.pop();
            }
            else if(obj.number.empty())
            {
                res.temp.push(number.top());
                number.pop();
            }
        }
        if(num[0]=='-' && obj.num[0]=='-') //if both number is negative
        {
            res.temp.top()*=(-1); // the result will be negative
        }
        return res;
    }

}

//overloading operator(-) to subtract two biginteger
bigint bigint ::operator-(bigint &obj2)
{
    bigint res2;
    bigint obj(obj2.num);
    int r,sz;
    //to check if any biginteger greater than other in digit
    if(number.size()<obj.number.size())
    {
        sz=number.size();
    }
    else
    {
        sz=obj.number.size();
    }

    //loop until the smallest size
    for(int i=0;i<sz;i++)
    {
        if(number.top()<obj.number.top()) //if the first digit in biginteger1 less than the first digit in biginteger2
        {
            //Subtract by credit
            number.top()+=10;
            r=number.top()-obj.number.top();
            number.pop();
            number.top()-=1;
            obj.number.pop();
            res2.temp.push(r);
        }
        else
        {
            r=number.top()-obj.number.top();
            number.pop();
            obj.number.pop();
            res2.temp.push(r);
        }

    }
    //if any biginteger is not empty
    while (!number.empty() || !obj.number.empty())
    {
        if(number.empty())
        {
            res2.temp.push(obj.number.top());
            obj.number.pop();
        }
        else if(obj.number.empty())
        {
            res2.temp.push(number.top());
            number.pop();
        }
    }
    //check if there is any 0 for the left in result
    int c=res2.temp.size();
    for(int i=0;i<c;i++)
    {
        if(res2.temp.top()==0 && i!=c-1)
        {
            res2.temp.pop();
        }
        else
        {
            break;
        }
    }
    return res2;
}

//overloading operator << to output the object
ostream & operator << (ostream& os, bigint &obj)
{
    while (!obj.temp.empty())
    {
        os<<obj.temp.top();
        obj.temp.pop();
    }
    return os;
}

int main()
{
    //add two positive big integers
    cout<<"Tast 1:"<<endl;
    bigint num1("123456789012345678901234567890");
    bigint num2("113456789011345678901134567890");
    bigint num3=num1+num2;
    cout<<"num1= "<<num1<<endl;  //123456789012345678901234567890
    cout<<"num2= "<<num2<<endl;  //113456789011345678901134567890
    cout<<"num1+num2= "<<num3<<endl;  //236913578023691357802369135780

    //add two negative big integers
    cout<<endl<<"Tast 2:"<<endl;
    bigint num4("-123456789012345678901234567890");
    bigint num5("-113456789011345678901134567890");
    bigint num6=num4+num5;
    cout<<"num4= "<<num4<<endl;  //-123456789012345678901234567890
    cout<<"num5= "<<num5<<endl;  //-113456789011345678901134567890
    cout<<"num4+num4= "<<num6<<endl;  //-236913578023691357802369135780

    //subtract two big integers (positive number is biggest)
    cout<<endl<<"Test 3:"<<endl;
    bigint num7("666666666666666666");
    bigint num8("-222222222222222222");
    bigint num9=num7+num8;
    cout<<"num7= "<<num7<<endl;  //666666666666666666
    cout<<"num8= "<<num8<<endl;  //-222222222222222222
    cout<<"num7+num8= "<<num9<<endl;  //444444444444444444

    //subtract two big integers (negative number is biggest)
    cout<<endl<<"Test 4:"<<endl;
    bigint num10("-666666666666666666");
    bigint num11("222222222222222222");
    bigint num12=num10+num11;
    cout<<"num10= "<<num10<<endl;  //-666666666666666666
    cout<<"num11= "<<num11<<endl;  //222222222222222222
    cout<<"num10+num11= "<<num12<<endl;  //-444444444444444444

    //add positive big integer to the (-ve) of the same big integer
    cout<<endl<<"Test 5:"<<endl;
    bigint num13("-44444444444444444");
    bigint num14("44444444444444444");
    bigint num15=num13+num14;
    cout<<"num13= "<<num13<<endl;  //-44444444444444444
    cout<<"num14= "<<num14<<endl;  //44444444444444444
    cout<<"num13+num14= "<<num15<<endl;  //0

    //add to big integers the diff between them -1
    cout<<endl<<"Test 6:"<<endl;
    bigint num16("-111111000000000001");
    bigint num17("111111000000000000");
    bigint num18=num16+num17;
    cout<<"num16= "<<num16<<endl;  //-111111000000000001
    cout<<"num17= "<<num17<<endl;  //111111000000000000
    cout<<"num16+num17= "<<num18<<endl;  //-1









    return 0;
}
