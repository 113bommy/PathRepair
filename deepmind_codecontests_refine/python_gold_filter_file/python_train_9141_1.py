# -*- coding:utf-8 -*-
n = int(input())
a = [int(i) for i in input().split()]
dp = [[x, 0] for x in range(0, len(a))]
 
 
def ins(x, i):
    if x in dp[i]:
        return
    if dp[i][0] != x and a[dp[i][0]] < a[x]:
        dp[i][1] = dp[i][0]
        dp[i][0] = x
    elif dp[i][1] != x and a[dp[i][1]] < a[x]:
        dp[i][1] = x
 
 
def mix(i, j):
    ins(dp[i][0], j)
    ins(dp[i][1], j)
 
 
for i in range(0, len(a)):
    for j in range(0, n):
        if i & (1 << j) == 0:
            mix(i, i | (1 << j))
 
 
ans = 0
for i in range(1, len(a)):
    u = a[dp[i][0]]+a[dp[i][1]]
    ans = max(ans, u)
    print(ans)