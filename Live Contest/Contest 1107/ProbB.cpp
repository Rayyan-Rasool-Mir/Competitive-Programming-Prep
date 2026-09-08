#include <iostream>
using namespace std;

bool isGood(long long n)
{
    bool seen[10] = {false};
    int count = 0;

    if (n == 0)
        return true;

    while (n > 0)
    {
        int digit = n % 10;
        if (!seen[digit])
        {
            seen[digit] = true;
            count++;
            if (count > 2)
            return false;

        }
        n /= 10;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        bool found = false;

        for (int length = 1; length <= 9 && !found; length++)
        {
            for (int digit = 1; digit <= 9; digit++)
            {
                long long y = 0;

                for (int i = 0; i < length; i++)
                    y = y * 10 + digit;

                if (y >= 2 && isGood(x * y))
                {
                    cout << y << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            for (long long y = 2; y <= 1000000; y++)
            {
                if (isGood(y) && isGood(x * y))
                {
                    cout << y << "\n";
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}