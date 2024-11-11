from math import gcd
N, M = map(int, input().split(" "))
S = input()
T = input()
G = gcd(N, M)
L = N * M // G
for i in range(G):
  if S[i*N//G] != T[i*M//G]:
    print(-1)
    exit(0)
print(L)

