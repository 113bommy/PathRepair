A, B, n, x = map(int, input().split())
MOD = 10 ** 19 + 7

def SD(i):
    if i == 0:
        return 1
    elif i % 2 == 0:
        return (1 + A * SD(i - 1)) % MOD
    else:
        md = pow(A, i // 2 + 1, MOD)
        return ((md + 1) * SD(i // 2)) % MOD

res = pow(A, n, MOD) * x + SD(n - 1) * B
print(res % MOD)