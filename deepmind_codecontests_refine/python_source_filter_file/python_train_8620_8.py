# coding: utf-8
# Your code here!
import sys
input = sys.stdin.readline

n=int(input())
A= [[int(i) for i in input().split()] for j in range(n)]

MOD=10**9+7
_ALL=1<<n
dp = [0]*(_ALL)
dp[0] = 1

for m in range(1,n+1):
    a = 1<<m-1
    while a < _ALL:
        for c,i in enumerate(A[m-1]):
            if (1<<c)&a and i:
                dp[a] += dp[a^(1<<c)]
                if dp[a] > MOD:
                    dp[a] -= MOD
        x = a & -a
        y = a + x
        a = (((a & ~y) // x) >> 1) | y

#print(dp)
print(dp[2**n-1])