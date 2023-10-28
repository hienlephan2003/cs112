#include <iostream>
#include <string>
using namespace std;

int k;
string num;
void deleteMin()
{
    int i = 0;
    while (k > 0)
    {
        if (num[i + 1] < num[i])
        {
            num.erase(i, 1);
            k--;
            if (i > 0)
                i--;
        }
        else
            i++;
    }
    cout << stoi(num);
}
int main()
{
    cin >> num;
    cin >> k;
    if (k == num.size())
        cout << "0";
    else if (k > num.size())
    {
        cout << "error";
    }
    else
    {
        deleteMin();
    }
}