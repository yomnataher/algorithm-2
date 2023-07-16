#include <iostream>
using namespace std;

int ack(int m, int n)
{
    if (m == 0) {
        return n + 1;
    }
    else if ((m > 0) && (n == 0)) {
        return ack(m - 1, 1);
    }
    else if ((m > 0) && (n > 0)) {
        return ack(m - 1, ack(m, n - 1));
    }
}

// Driver code
int main()
{
    int m,n;
    cout << "Enter the first num :" << endl;
    cin >> m;
    cout << "Enter the sec. num:" << endl;
    cin >> n;

    cout <<"The Ackermann resulte: "<< ack(m, n) << endl;
   
   
    return 0;
}