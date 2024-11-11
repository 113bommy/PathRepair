MOD = 10**9 + 7
K = input()
D = int(input())
N = len(K)
dp0 = [[0] * D for _ in range(N+1)]
dp1 = [[0] * D for _ in range(N+1)]
dp0[0][0] = 1
for i, digit in enumerate(K, 1):
    digit = int(digit)
    for d in range(D):
        for k in range(10):
            dp1[i][(d + k) % D] += dp1[i-1][d]
            dp1[i][(d + k) % D] %= MOD
            if k < digit:
                dp1[i][(d + k) % D] += dp0[i-1][d]
                dp1[i][(d + k) % D] %= MOD
            elif k == digit:
                dp0[i][(d + k) % D] += dp0[i-1][d]
                dp0[i][(d + k) % D] %= MOD
print((dp0[N][0] + dp1[N][0] - 1) % MOD)