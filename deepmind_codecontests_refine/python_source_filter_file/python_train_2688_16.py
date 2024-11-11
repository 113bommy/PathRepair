from fractions import gcd


N, M = map(int, input().split())
S, T = [input() for _ in range(2)]
L = gcd(N, M)
print(N*M//L if any([S[i*N//L] == T[i*M//L] for i in range(L)]) else -1)
