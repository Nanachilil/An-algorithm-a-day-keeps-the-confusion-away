#include <cstdint>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int T, n;

inline int read()
{
    int ret = 0, f = 1, ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar(); // skip non-digit characters
    }
    while (ch >= '0' && ch <= '9')
        ret = ret * 10 + (ch & 15), ch = getchar();
    return ret * f;
}

void _solve()
{
    n = read();
    if (n & 1)
    {
        printf("-1\n");
        return;
    }

    printf("(");
    for (int i = 1; i <= (n - 2) >> 1; i++)
    {
        if (i <= (n - 2) >> 2)
            printf(")(");
        else
            printf("()");
    }
    printf(")\n");
}

signed main()
{
    T = read();
    while (T--)
        _solve();
    return 0;
}
