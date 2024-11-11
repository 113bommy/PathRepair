from math import *
n,l,r=[int(i) for i in input().split()]
k=[]
lr=10**9 +7
for i in range(3):
    k.append((r-i)//3 - (l-i-1)//3)
#print(k)
dp=(1,0,0)
for i in range(n):
    dp=((dp[0]*k[0] + dp[2]*k[1] + dp[1]*k[2])%lr,(dp[0]*k[1] + dp[1]*k[0]+ dp[2]*k[2])%lr,(dp[0]*k[2] + dp[2]*k[0]+ dp[1]*k[1])%lr)
print(dp[0])
