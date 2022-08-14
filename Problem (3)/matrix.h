#ifndef DATA_STRUCTURE_FINAL_MATRIX_MATRIX_H
#define DATA_STRUCTURE_FINAL_MATRIX_MATRIX_H
#include <iostream>

using namespace std;


//class Matrix has the operations
template <class t>
class Matrix
{
private:
    int row,colm;
    t**arr;

public:
    //default constructor
    Matrix()
    {
    }
    //parameterize constructor allocating the required memory space based on the dimensions
    Matrix(int r,int c)
    {
        row=r;
        colm=c;
        arr=new t*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new t[colm];
        }
    }
    //copy constructor
    Matrix(const Matrix & obj)
    {
        row = obj.row;
        colm = obj.colm;
        arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[colm];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                arr[i][j] = obj.arr[i][j];
            }
        }
    }

    //overloading operator >> to input the dimensions and the elements of the Matrix
    template <class t2>
    friend istream& operator>>(istream & is,Matrix<t2> & obj)
    {
        cout<<"Enter the dimensions:"<<endl;
        cout<<"row= ";
        is>>obj.row;
        cout<<"colm= ";
        is>>obj.colm;
        obj.arr=new t2*[obj.row];
        for(int i=0;i<obj.row;i++)
        {
            obj.arr[i]=new t2[obj.colm];
        }
        cout<<endl<<"Enter the elements of your Matrix: "<<endl;
        for(int i=0;i<obj.row;i++)
        {
            for(int j=0;j<obj.colm;j++)
            {
                is>>obj.arr[i][j];
            }
        }
        cout<<endl;
    }

    //overloading operator << to output the Matrix
    friend ostream& operator<<(ostream & os,const Matrix<t> &obj)
    {
        os<<endl<<"Result:"<<endl;
        for(int i=0;i<obj.row;i++)
        {
            for(int j=0;j<obj.colm;j++)
            {
                os<<obj.arr[i][j]<<" ";
            }
            os<<endl;
        }
        os<<endl;
        return os;
    }

    //overloading operator + to addition two Matrix
    Matrix operator+(const Matrix<t> & mtx)
    {
        Matrix<t> res(mtx.row,mtx.colm);
        for(int i=0;i<res.row;i++)
        {
            for(int j=0;j<res.colm ;j++)
            {
                res.arr[i][j]=arr[i][j]+mtx.arr[i][j];
            }
        }
        return res;
    }

    //overloading operator - to subtract two Matrix
    Matrix operator-(const Matrix<t> &mtx)
    {
        Matrix<t> res(mtx.row,mtx.colm);
        for(int i=0;i<res.row;i++)
        {
            for(int j=0;j<res.colm ;j++)
            {
                res.arr[i][j]=arr[i][j]-mtx.arr[i][j];
            }
        }
        return res;
    }
    //overloading operator * to multiplication two Matrix
    Matrix operator*(const Matrix &mtx)
    {
        Matrix<t> res(row,mtx.colm);
        int sum;
        for(int i=0;i<res.row;i++)
        {
            for(int j=0;j<res.colm ;j++)
            {
                sum=0;
                for(int x=0;x<colm;x++)
                {
                    sum+=arr[i][x]*mtx.arr[x][j];
                }
                res.arr[i][j]=sum;
            }
        }
        return res;
    }

    //function to transpose the matrix
    Matrix<t> Transpose()
    {
        Matrix<t> r(colm,row);
        for(int i=0;i<r.row;i++)
        {
            for(int j=0;j<r.colm;j++)
            {
                r.arr[i][j]=arr[j][i];
            }
        }
        return r;
    }

    //to get the numbers rows
    int getrow()
    {
        return row;
    }

    //to get the number of columns
    int getcolm()
    {
        return colm;
    }

    //destructor that frees used memory at the end of lifetime of each Matrix objects
   ~Matrix()
    {
        for(int i=0;i<row;i++)
        {
            delete []arr[i];
        }
        delete []arr;
    }

};

//Function to check that two matrices are of dimensions the same (n x m and n x m) To addition and subtraction
template <class t>
bool check (Matrix <t>obj1, Matrix<t> obj2)
{
    if (obj1.getrow() != obj2.getrow() ||obj1.getcolm() !=obj2.getcolm())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// function to check that two matrices are of dimensions (n x m and m x p) To multiplication
template <class t>
bool check_Mul(Matrix <t>obj1, Matrix<t> obj2)
{
    if (obj1.getcolm() != obj2.getrow())
    {
        return false;
    }
    else
    {
        return true;
    }
}


#endif //DATA_STRUCTURE_FINAL_MATRIX_MATRIX_H
