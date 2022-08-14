//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

//Abstract class
class sorter {
protected:
    ll size;
    ll *arr;
public:
    //set function to set array size and reject the wrong size
    void SetSize(ll sz)
    {
        if (sz >= 0)
        {
            size = sz;
        }
        else {
            cout << "Invalid data" << endl;
        }
    }

    //default constructor
    sorter()
    {
    }

    //virtual function
    virtual void sort(ll arr[], ll n)
    {
    }
    virtual ~sorter()
    {
        delete []arr;
    }
};

//inheritance class from class sorter
class SelectionSorter : public sorter
{
public:
    //default contractor
    SelectionSorter() : sorter()
    {
    }

    //overriding function to selection sort
    void sort(ll v[], ll n) {
        SetSize(n);
        arr = new ll[size];
        for (ll i = 0; i < n; ++i)
        {
            arr[i] = v[i];
        }
        ll minIdx;
        for (ll i = 0; i < n - 1; i++) {
            minIdx = i;
            for (ll j = i + 1; j < n; j++)
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            swap(arr[minIdx], arr[i]);
        }
    }
};

//inheritance class from class sorter
class QuickSorter : public sorter
{
public:
    //default contractor
    QuickSorter() : sorter()
    {
    }

    //overriding function
    void sort(ll v[], ll n)
    {
        SetSize(n);
        arr = new ll[size];
        for (ll i = 0; i < n; ++i)
        {
            arr[i] = v[i];
        }
        quickSort(arr, 0, n - 1);
    }
    //quick sort function
    void quickSort(ll a[], ll first, ll last)
    {
        ll start = first, end = last;
        ll mid = (first + last) / 2;
        ll temp;
        while (start <= end) {
            while (a[start] < a[mid])
            {
                start = start + 1;
            }
            while (a[end] > a[mid])
            {
                end = end - 1;
            }
            if (start <= end)
            {
                temp = a[start];
                a[start] = a[end];
                a[end] = temp;
                start++;
                end--;
            }
        }
        if (first < end)
        {
            quickSort(a, first, end);
        }
        if (start < last)
        {
            quickSort(a, start, last);
        }
    }
};

//testbed class has the following functions
class Testbed
{
public:
    //function to generate lite with random integers
    long long GenerateRandomList(ll min, ll max, ll size)
    {
        ll list[size];
        srand(time(NULL));
        for (ll i = 0; i < size; ++i) {
            list[i] = rand() % (max - min + 1) + min;
        }
        return *list;
    }

    //function to order the list with decanting
    ll GenerateReverseOrderedList(ll min, ll max, ll size)
    {
        ll list[size];
        *list = GenerateRandomList(min, max, size);
        sort(list, list + size, greater<ll>());
        return *list;
    }

    //function to calculate the time for one list
    ll RunOnce(sorter *s, ll data[], ll size) {
        auto start = chrono::high_resolution_clock::now();
        s->sort(data, size);
        auto elapsed = chrono::high_resolution_clock::now();
        auto microseconds = chrono::duration_cast<chrono::microseconds>(elapsed - start);
        return microseconds.count();
    }

    //function to calculate the average time for many list(sets_num)
    ll RunAndAverage(sorter *s, int type, ll min, ll max, ll size, ll sets_num) {
        ll time1 = 0 , time2 = 0;
        ll avg1 = 0 , avg2 = 0;

        //if the type "Random" the creat list with random values
        if (type == 0)
        {
            ll arrRand[size];
            for (ll i = 0; i < sets_num; ++i)
            {
                *arrRand = GenerateRandomList(min, max, size);
                time1 += RunOnce(s, arrRand, size);
            }
            avg1 = (time1 / sets_num);
            return avg1;
        }

        else    //if the type "Reverse" the creat list with reverse values
        {
            ll arrReverse[size];
            for (ll i = 0; i < sets_num; ++i)
            {
                *arrReverse = GenerateReverseOrderedList(min, max, size);
                time2 += RunOnce(s, arrReverse, size);
            }
            avg2 = (time2 / sets_num);
            return avg2;
        }
    }
    //Develop an experiment to run a given sorting algorithm and calculate its performance on sets of different sizes
    void RunExperient(sorter *s, int type, ll min, ll max, ll min_val, ll max_val, ll sets_num, ll step)
    {
        cout << "Size" << setw(20) << "AverageTime" << endl;
        for (ll i = min_val; i <= max_val; i += step)
        {
            cout << i << right<<setw(15) << RunAndAverage(s, type, min, max, i, sets_num) << endl;
        }
    }

};

int main()
{
    Testbed b;

    cout<<"<<Random>>"<<endl;

    //call selection sort with type (random)
    cout<<"SelectionSort:" << endl;
    sorter *s = new SelectionSorter;
    b.RunExperient(s, 0, 0, 100000, 0, 110000, 5, 10000);
    delete s;

    //call Quick sort with type (random)
    cout <<endl<< "QuickSort:" << endl;
    sorter *Q = new QuickSorter;
    b.RunExperient(Q, 0, 0, 100000, 0, 110000, 5, 10000);
    delete Q;

    cout<<endl<<"<<Reverse>>"<<endl;

    //call selection sort with type (reverse)
    cout <<endl<< "SelectionSort:" << endl;
    sorter *ss = new SelectionSorter;
    b.RunExperient(ss, 1, 0, 100000, 0, 110000, 5, 10000);
    delete ss;

    //call Quick sort with type (reverse)
    cout <<endl<< "QuickSort:" << endl;
    sorter *QQ = new QuickSorter;
    b.RunExperient(QQ, 1, 0, 100000, 0, 110000, 5, 10000);
    delete QQ;


    return 0;
}
