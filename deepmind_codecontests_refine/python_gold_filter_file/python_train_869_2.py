from math import ceil,sqrt
from collections import defaultdict




def solve():


    n,m = map(int,input().split())

    l = []
    for i in range(n):
        a,b = map(float,input().split())
        l.append(a)

    dp = [0]*(n)

    for i in range(n):
        maxi = 0
        for j in range(i):
           if l[i]>=l[j]:
             maxi = max(dp[j],maxi)

        dp[i] = maxi+1
    # print(dp)
    print(n-max(dp))















# t = int(input())
# for _ in range(t):

solve()


