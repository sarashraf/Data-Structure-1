//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178


#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
using namespace std;

//Sorting the songs using insertion sort
void BiasedSort(vector<string> &v, int len) {
    int i, j;
    string key;

    for (i = 1; i < len; i++) {
        key = v[i];
        j = i - 1;
        //While loop to insert songs with name "untitled" at first
        while (j >= 0 && key == "untitled") {

            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
        // while loop to sort the remaining songs alphabetically
        while (j >= 0 && v[j] > key && v[j] != "untitled") {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// Function to print the list after doing the sort algorithm
void print(vector<string> &v, int len) {
    int cnt = 1;
    cout << "Songs after sorting " << endl;
    for (int i = 0; i < len; ++i) {
        cout << cnt << ": " << v[i] << endl;
        cnt++;
    }
}

int main() {
    int n;
    cout << "Enter number of songs in the list" << endl;
    cin >> n;
    vector<string> v(n);
    cout << "Enter names of songs,please" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    BiasedSort(v, n);
    print(v, n);
    return 0;
}
