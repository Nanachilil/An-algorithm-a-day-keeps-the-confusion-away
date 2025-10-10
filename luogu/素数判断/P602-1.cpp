#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

// √n 试除法（6k±1 优化）
bool isPrime_sqrt(long long n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// 埃氏筛，预处理到 MAXV
vector<bool> sieve_up_to(int MAXV)
{
    vector<bool> is_prime(MAXV + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 1LL * i * i <= MAXV; i++)
    {
        if (is_prime[i])
        {
            for (long long j = 1LL * i * i; j <= MAXV; j += i)
            // 最小素数 i 的倍数从 i*i 开始筛，之后每次加 i
            {
                is_prime[(size_t)j] = false;
            }
        }
    }
    return is_prime;
}

// =============== Miller–Rabin =================
// 快速幂取模
long long modpow(long long a, long long d, long long n)
{
    long long res = 1 % n;
    while (d > 0)
    {
        if (d & 1)
            res = (__int128)res * a % n;
        a = (__int128)a * a % n;
        d >>= 1;
    }
    return res;
}

// Miller–Rabin 判素数 (确定性版本，支持 32 位整数)
bool isPrime_MR(uint64_t n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return n == 2;
    if (n % 3 == 0)
        return n == 3;

    // 分解 n-1 = 2^r * d
    uint64_t d = n - 1, r = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    // 32 位以内只要这 3 个基数
    static const int bases[] = {2, 7, 61};

    for (int a : bases)
    {
        if ((uint64_t)a % n == 0)
            continue;
        long long x = modpow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        bool composite = true;
        for (uint64_t i = 1; i < r; i++)
        {
            x = (__int128)x * x % n;
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false; // 合数
    }
    return true; // 素数
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int32_t x0, y0; // 种子必须用 32 位
    cin >> T >> x0 >> y0;

    const int LIM = 10000;
    auto isPrimeSmall = sieve_up_to(LIM);

    long long ans = 0;

    while (T--)
    {
        // 更新 x0
        int32_t tmp1 = (int32_t)((long long)7 * x0 + 13);
        int32_t tmp2 = (int32_t)(x0 / 13 - 7); // 整除是向零取整
        x0 = (int32_t)(tmp1 ^ tmp2);

        // 更新 y0
        tmp1 = (int32_t)((long long)7 * y0 + 13);
        tmp2 = (int32_t)(y0 / 13 - 7);
        y0 = (int32_t)(tmp1 ^ tmp2);

        // 映射到 [1,10000]
        int x = ((x0 % LIM + LIM) % LIM) + 1;
        int y = ((y0 % LIM + LIM) % LIM) + 1;

        // x, y 必须是素数
        if (!isPrimeSmall[x] || !isPrimeSmall[y])
            continue;

        // z = x*y - 3*(x-y)
        long long z = 1LL * x * y - 3LL * (x - y);
        if (isPrime_sqrt(z))
        {
            ans++;
        }

        cout << ans << "\n";
        return 0;
    }
}
