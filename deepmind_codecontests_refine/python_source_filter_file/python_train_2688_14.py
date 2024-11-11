N,M=map(int,input().split())
S=input()
T=input()
from math import gcd
g=gcd(N,M)
L=N*M//g
for i in range(g):
    if S[i*N//g]!=T[i*M//g]:
        print(-1)
        break
else:
    print(L)