N, M = map(int, input().split())
S = input()
T = input()

from math import gcd

def solve(N,M,S,T):
    g = gcd(N,M)
    for i in range(g):
        if S[N//g*i]!=T[M//g*i]:
            return -1
    ans = N*M//g
    return ans
print(solve(N,M,S,T))