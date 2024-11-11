#coding:utf-8
'''
Created on 2021年4月6日

@author: lzh
'''

import math

n, d = map(int, input().split())
arr = [int(_) for _ in input().split()]

dp = [[-1e6 for _ in range(0, 10)] for _ in range(n + 1)]
path = [[(0, 0, 0) for _ in range(0, 10)] for _ in range(n + 1)]

dp[0][1] = 0

for i in range(n) :
    for j in range(10):
        val = dp[i][j] + math.log(arr[i])
        if dp[i + 1][(j * arr[i])%10] <= val:
            dp[i + 1][(j * arr[i])%10] = val
            path[i + 1][(j * arr[i])%10] = (i, j, 1)
        
        val = dp[i][j]
        if dp[i + 1][j] <= val:
            dp[i + 1][j] = val
            path[i + 1][j] = (i, j , 0)

ans = []
test, pd = 1, d
while n > 0 :
    if path[n][d][2] == 1:
        ans.append(arr[n - 1])
        test = (test * arr[n - 1])%10
    
    n,d = path[n][d][:2]

if test == pd and len(ans) > 0:
    print(len(ans))
    print(' '.join(map(str, ans)))
else:
    print(-1)
