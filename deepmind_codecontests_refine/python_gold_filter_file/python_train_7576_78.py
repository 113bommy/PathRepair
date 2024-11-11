N = int(input())
A = [int(x) for x in input().split()]

import fractions

G = A[0]
for i in range(1,N):
    G = G * A[i] // fractions.gcd(G, A[i])

ans = 0
for j in range(N):
    ans += G // A[j]

print(ans % (10 ** 9 + 7))