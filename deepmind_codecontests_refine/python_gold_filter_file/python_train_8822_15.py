MOD = 10**9 + 7
x, k = map(int, input().split())
y = (2*x - 1) % MOD
mult = pow(2, k, MOD)
if x:
    print((y * mult + 1) % MOD)
else:
    print(0)