//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178


#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int binarySearch(int arr[], int i, int j, int target_place) {
    int mid;
    while (j >= i) {
        mid = (i + j) / 2;
        // we atr trying to find the location of target place in the array
        // if the element in the half of the array is equal to target so return its place
        if (arr[mid] == target_place) {
            return mid;
        }
            // the target element is greater than the element in the half so, it must be not in the left element of the array

        else if (arr[mid] < target_place) {
            // move i to the first next element to the mid of the array
            i = mid + 1;
        } else {
            // the target element is smaller than the element in the half so, it must be not in the right element of the array

            // move j to the first previous element to the mid of the array

            j = mid - 1;
        }
    }
    // return -1 means that the element is not found
    return -1;
}

void binaryInsertionSort(int arr[], int n) {
    int i, temp, j, location = 0;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        //calling binary search function to find the place of the element faster than reqular insertion search
        location = binarySearch(arr, 0, i - 1, temp);
        while (j >= location) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//Regular insertion sort function
void insertionSort(int arr[], int n) {
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int *binary_array;
    int n;
    //generation random numbers
    srand(time(NULL));
    auto f1 = []() -> int {
        return rand();
     };
    cout << "Enter a big size for both methods to see a real difference" << endl;
    cout << "please enter the size of the array you want to generate: " << endl;
    cin >> n;
    cout<<endl;
    binary_array = new int[n];
    generate(binary_array, binary_array + n, f1);
    auto start = chrono::high_resolution_clock::now();
    binaryInsertionSort(binary_array, n);
    auto elapsed = chrono::high_resolution_clock::now();
    auto microseconds = chrono::duration_cast<chrono::microseconds>(elapsed - start);
    // Note that difference of both function in time complexity not much significant and it is expected in small sizes with a better case for insertion time to be small
    cout << microseconds.count() << " microseconds using binary search" << endl;

    int *insertion_sort;
    auto f2 = []() -> int {
        return rand() ;
        };

    insertion_sort = new int[n];
    generate(insertion_sort, insertion_sort + n, f2);
    auto stt = chrono::high_resolution_clock::now();
    insertionSort(insertion_sort, n);
    auto elapsd = chrono::high_resolution_clock::now();
    auto microsecon = chrono::duration_cast<chrono::microseconds>(elapsd - stt);
    cout << microsecon.count() << " microseconds using insertion sort" << endl;

    return 0;
}
