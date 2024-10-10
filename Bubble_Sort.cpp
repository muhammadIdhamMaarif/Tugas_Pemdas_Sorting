#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void swap (int &a, int &b) {
    int sigma = b;
    b = a;
    a = sigma;
}

void urutkan(vector<int> &arr) {
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}

int maksimum(vector<int> arr) {
    int maks = numeric_limits<int>::min();
    for (const int &i : arr) {
        maks = max(i, maks);
    }
    return maks;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << endl << endl;
    
    cout << "Array sebelum diurutkan adalah " << endl;
    for (const int &i : arr) {
        cout << i << " ";
    }
    
    cout << endl << endl;
    
    urutkan(arr);

    cout << "Nilai Maksimal Adalah " << maksimum(arr) << endl << endl;
    
    cout << "Array setelah diurutkan adalah " << endl;
    for (const int &i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
}
