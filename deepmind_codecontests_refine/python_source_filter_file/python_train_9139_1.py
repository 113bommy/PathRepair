MOD = 10**6+3
n = MOD + 10
fac = [1] + [0] * n
for i in range(1, n+1):
    fac[i] = fac[i-1] * (i) % MOD

q = int(input())

def f(x, d, n):
    if d == 0:
        return pow(x, n, MOD)
    p = (x * pow(d, MOD-2, MOD)) % MOD
    if p + n - 1 >= MOD:
        return 0
    q = fac[(p + n - 1) % MOD]
    r = fac[p - 1]
    s = pow(d, n, MOD)
    return (q*pow(r, MOD-2, MOD)*s) % MOD

for i in range(q):
    x, d, n = [int(item) for item in input().split()]
    print(f(x, d, n))