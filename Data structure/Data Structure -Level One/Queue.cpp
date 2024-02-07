#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> queNumbers;

    queNumbers.push(10);
    queNumbers.push(20);
    queNumbers.push(30);
    queNumbers.push(40);
    queNumbers.push(50);

    cout << "Count = " << queNumbers.size() << endl;

    while (!queNumbers.empty())
    {
        cout << queNumbers.front() << " ";

        queNumbers.pop();

        cout << "\n stack size: ";
        cout << queNumbers.size();
        cout << endl;
    }

    return 0;
}