MOD = 10 ** 9 + 7

def kaijo(n):
    k = 1
    for i in range(1, n + 1):
        k *= i % MOD
    return k

n, m = map(int, input().split())
if n == m:
    print((kaijo(n) ** 2 * 2) % MOD)
elif abs(n - m) > 1:
    print(0)
else:
    if n < m:
        print((kaijo(n) ** 2 * m) % MOD)
    else:
        print((kaijo(m) ** 2 * n) % MOD)