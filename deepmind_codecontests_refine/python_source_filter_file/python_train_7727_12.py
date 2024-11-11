MOD = 998244353
pow10 = [1] * (2 * 10**5 + 1)
for i in range(1, 10**5 + 2):
    pow10[i] = pow10[i - 1] * 10
    pow10[i] %= MOD
n = int(input())
for i in range(1, n):
    print(((2 * pow10[n - i - 1] * 9 + max(0, n - i - 1) * pow10[max(0, n - i - 2)] * 81) * 10) % MOD, end=' ')
print(10)
