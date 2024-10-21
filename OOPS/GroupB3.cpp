#include<iostream>
using namespace std;

#define Size 10
int n;

template <class T>
void selection(T A[Size]) {
    int i, j, Min;
    T temp;
    
    for (i = 0; i <= n - 2; i++) {
        Min = i;
        for (j = i + 1; j <= n - 1; j++) {
            if (A[j] < A[Min])
                Min = j;
        }
        temp = A[i];
        A[i] = A[Min];
        A[Min] = temp;
    }

    cout << "\nThe sorted list is:\n";
    for (i = 0; i < n; i++)
        cout << "\t" << A[i];
}

int main() {
    int i, A[Size];
    float B[Size];
    
    cout << "\n\t\tSelection Sort\n";
    
    cout << "\nHandling Integer elements\n";
    cout << "How many elements are there? ";
    cin >> n;
    cout << "\nEnter the integer elements:\n";
    for (i = 0; i < n; i++)
        cin >> A[i];
    
    selection(A);
    
    cout << "\n\nHandling Float elements\n";
    cout << "How many elements are there? ";
    cin >> n;
    cout << "\nEnter the float elements:\n";
    for (i = 0; i < n; i++)
        cin >> B[i];
    
    selection(B);
    
    cout << "\n";
    return 0;
}
