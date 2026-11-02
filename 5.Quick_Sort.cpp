#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int comparisons = 0, swaps = 0;

// Deterministic Quick Sort Partition
int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {

        while (i <= high && a[i] <= pivot) {
            comparisons++;
            i++;
        }

        while (j >= low + 1 && a[j] > pivot) {
            comparisons++;
            j--;
        }

        if (i < j) {
            swap(a[i], a[j]);
            swaps++;
        }
        else {
            break;
        }
    }

    swap(a[low], a[j]);
    swaps++;

    return j;
}

// Deterministic Quick Sort
void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort Partition
int randomPartition(vector<int>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[low], a[randomIndex]);
    swaps++;

    return partition(a, low, high);
}

// Randomized Quick Sort
void randomQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = randomPartition(a, low, high);

        randomQuickSort(a, low, p - 1);
        randomQuickSort(a, p + 1, high);
    }
}

// Display array
void display(vector<int> a) {
    for (int x : a)
        cout << x << " ";

    cout << endl;
}

int main() {
    srand(time(0));

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int choice;

    while (true) {
        cout << "\n1. Deterministic Quick Sort";
        cout << "\n2. Randomized Quick Sort";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {

            vector<int> b = a;

            comparisons = 0;
            swaps = 0;

            auto start = chrono::high_resolution_clock::now();

            quickSort(b, 0, n - 1);

            auto end = chrono::high_resolution_clock::now();

            cout << "\nDeterministic Quick Sort\n";
            cout << "Sorted array: ";
            display(b);

            cout << "Comparisons: " << comparisons << endl;
            cout << "Swaps: " << swaps << endl;

            cout << "Execution time: "
                 << chrono::duration<double, milli>(end - start).count()
                 << " ms\n";
        }

        else if (choice == 2) {

            vector<int> b = a;

            comparisons = 0;
            swaps = 0;

            auto start = chrono::high_resolution_clock::now();

            randomQuickSort(b, 0, n - 1);

            auto end = chrono::high_resolution_clock::now();

            cout << "\nRandomized Quick Sort\n";
            cout << "Sorted array: ";
            display(b);

            cout << "Comparisons: " << comparisons << endl;
            cout << "Swaps: " << swaps << endl;

            cout << "Execution time: "
                 << chrono::duration<double, milli>(end - start).count()
                 << " ms\n";
        }

        else if (choice == 3) {
            cout << "Program terminated.";
            break;
        }

        else {
            cout << "Invalid choice!";
        }
    }

    return 0;
}
