import sys
input = sys.stdin.readline


mod = 998244353
N = int(input())
A = [int(input()) for _ in range(N)]

S = sum(A)
L = S//2
dp1 = [0]*(L+1)
dp2 = [0]*(L+1)
dp1[0] = 1
dp2[0] = 1
for a in A:
    for i in reversed(range(L-a+1)):
        dp1[i+a] = (dp1[i+a] + dp1[i])%mod
        dp2[i+a] = (dp2[i+a] + dp2[i]*2)%mod

p1 = 0
p2 = 0
for s in range(1,L+1):
    p1 = (p1 + dp1[s]*6)%mod
    p2 = (p2 + dp2[s]*3)%mod
ans = (pow(3, N, mod) + 3 - 3*pow(2, N, mod) - p2 + p1) % mod
print(ans)