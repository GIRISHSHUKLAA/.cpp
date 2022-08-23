#include <iostream>
using namespace std;
int main()
{
    // declaring elemnts
    int arr[10], i, num, index;
    cout << "Enter the elemnts";
    // taking input in an array
    for (i = 0; i < 10; i++)
        cin >> arr[i];
    cout << "Enter the number";
    cin >> num;
    // linear sesrch
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == num)
        {
            index = i;
            break;
        }
    }
    cout << "Element found" << index;
    cout << endl;
    return 0;
}
