# coding: utf-8
# Your code here!
n=int(input())
a = [int(i) for i in input().split()]
import sys
sys.setrecursionlimit(10**7)

ko = [0]*4
for i in a:
    ko[i] += 1

dp = [[[0.0]*(n+1) for i in range(n+1)] for j in range(n+1)]

cc=ko[1]+ko[2]+ko[3]
ccc=ko[2]+ko[3]
for k in range(ko[3]+1):
    for j in range(ccc+1-k):
        for i in range(cc+1-k-j):
            t=i+j+k
#            print(i,j,k)
            if i != 0:
                dp[i][j][k] += (dp[i-1][j][k] + n/t)*i/t
            if j != 0 and i < n:
                dp[i][j][k] += (dp[i+1][j-1][k] + n/t)*j/t
            if k != 0 and j < n:
                dp[i][j][k] += (dp[i][j+1][k-1] + n/t)*k/t
#print(dp)
print(dp[ko[1]][ko[2]][ko[3]])
