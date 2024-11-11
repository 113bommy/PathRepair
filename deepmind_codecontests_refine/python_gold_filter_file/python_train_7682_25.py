# -*- coding utf-8 -*-
import math


def calc_C(n, r):
    return (math.factorial(n) // (math.factorial(n - r) * math.factorial(r))) % (10**9 + 7)


N, M, K = map(int, input().split())

ans = 0

# row
for i in range(N):
    ans += i * (N - i) * M * M % (10**9 + 7)

# col
for i in range(M):
    ans += i * (M - i) * N * N % (10**9 + 7)

ans = ans % (10**9 + 7)
ans = ans * calc_C(N * M - 2, K - 2) % (10**9 + 7)
print(ans)
