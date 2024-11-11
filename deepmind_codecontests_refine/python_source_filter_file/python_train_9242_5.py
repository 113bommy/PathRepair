N, K = map(int, input().split())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

A.sort()

factorial = [1]
for i in range(1, N + 1):
    factorial.append(factorial[-1] * i)
inv_factorial = [-1] * (N + 1)
inv_factorial[-1] = pow(factorial[-1], MOD - 2, MOD)
for i in reversed(range(N)):
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD


ans = 0
for i in range(N - K + 1):
    c = factorial[N - 1 - i] * inv_factorial[K - 1] * inv_factorial[N - K - i]
    ans += c * (A[-1 - i] - A[i])
    ans %= MOD

print(ans)
