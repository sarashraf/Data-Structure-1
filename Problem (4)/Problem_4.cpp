//1)Sara Ashraf Ali 20200215
//2)Toka Hamdy Mohamed 20201048
//3)Merahan Soliman Mohamed 20200574
//4)Menna allah Mohamed Ibrahim 20201178

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'


using namespace std;

void RecPermute(string soFar, string rest) {
    //Declaring a vector to store all the strings have been printed in order to avoid printing it again
    vector<string> v;
    if (rest == "") // No more characters
        cout << soFar << endl; // Print the word
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            // For the first time vector will be empty so string "next" is pushed directly
            if (v.empty()) {
                v.push_back(next);
                RecPermute(next, remaining);
            }
            // Boolean to check if the string is printed before or not
            bool found = false;
            for (int j = 0; j < v.size(); ++j) {
                if (v[j] == next) {
                    //if found is true it means the string is printed before
                    found = true;
                }
            }
            if (found) {
                // if the string is already printed before it is not going to be printed again
                continue;
            } else {
                // if not the string will be printed and push it into the vector
                v.push_back(next);
                RecPermute(next, remaining);
            }
        }
}

// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}

int main() {
    string str;
    cout << "Please enter a string to list its permutations" << endl;
    cin >> str;
    ListPermutations(str);

    return 0;
}
