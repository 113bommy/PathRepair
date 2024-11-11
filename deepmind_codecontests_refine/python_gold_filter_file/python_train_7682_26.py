N, M, K = map(int, input().split())

MOD = 10 ** 9 + 7

def combination(n, m):
    c = 1
    m = min(n-m, m)
    for i in range(m):
        c = c * (n-i) * pow(m-i, MOD-2, MOD) % MOD
    return c

pattern = combination(N*M-2, K-2)

def diff_x_pattern(val):
    ret = 0
    for d in range(1, val):
        ret += ((val - d) * d) % MOD
    return ret

ans = (M * M * diff_x_pattern(N)) % MOD
ans += (N * N * diff_x_pattern(M)) % MOD
print((ans*pattern)%MOD)
