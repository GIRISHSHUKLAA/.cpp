#include <iostream>
using namespace std;

void Bubble_Sort(int vec[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
}
int main()
{
    int vec[] = {5, 3, 4, 2, 1};
    int n = sizeof(vec) / sizeof(vec[0]);
    Bubble_Sort(vec, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}
