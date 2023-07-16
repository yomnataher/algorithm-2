#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int policeThief(char arr[], int n, int k) {
    int caught = 0;
    vector<int> thieves;
    vector<int> policemen;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            policemen.push_back(i);
        else if (arr[i] == 'T')
            thieves.push_back(i);
    }

    int thief = 0, police = 0;
    while (thief < thieves.size() && police < policemen.size()) {
        if (abs(thieves[thief] - policemen[police]) <= k) {
            caught++;
            thief++;
            police++;
        }
        else if (thieves[thief] < policemen[police])
            thief++;
        else
            police++;
    }
    return caught;
}
int main() {
    int k;
    char arr[100];
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter k: \n";
    cin >> k;

    cout << "Enter N: \n ";
    cin >> n;

    cout << "Enter 'P' for policeman or a 'T'for thief \n" ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Maximum number of thieves that can be caught by police is :";
    cout<< policeThief(arr, n, k)<<"\n";
    return 0;
}