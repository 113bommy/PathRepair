# -*- coding: utf-8 -*-
"""
Created on Sun Apr 21 18:51:07 2019

@author: Yamazaki Kenichi
"""

N = int(input())
A = [int(input()) for i in range(N)]
mod = 998244353
def mof(x):
    return x % mod
total = sum(A)
dp1 = [[0 for i in range(300*N+1)] for i in range(N+1)]
dp2 = [[0 for i in range(300*N+1)] for i in range(N+1)]
dp1[0][0], dp2[0][0] = 1,1
for i in range(N):
    for j in range(N*300+1):
        dp1[i+1][j] = mof(dp1[i][j]*2 + (dp1[i][j-A[i]] if j >= A[i] else 0))
        dp2[i+1][j] = mof(dp2[i][j] + (dp2[i][j-A[i]] if j >= A[i] else 0))
        
ex = mof(sum(dp1[N][(total+1)//2:]))
a = dp2[N][total//2] if total % 2 == 0 else 0

ans = mof(3**N - 3*ex + 2*a)
print(ans)
