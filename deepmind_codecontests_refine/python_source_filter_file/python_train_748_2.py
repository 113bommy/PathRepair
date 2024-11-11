# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 19:52:50 2020

@author: Rodro
"""

def garland(a):
    n = len(a)
    a = [0] + a
    oo = n + 1
    dp = [[[oo, oo] for __ in range(n + 1)] for _ in range(n + 1)]
    dp[0][0][0] = dp[0][0][1] = 0
    for i in range(1, n + 1):
        for j in range(i + 1):
            if a[i]%2 == 1 or a[i] == 0:
                dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1])
            if a[i]%2 == 0 and j > 0:
                dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1)
    m = int(n/2)
    print(dp)
    return min(dp[n][m])

c1 = int(input())
c2 = str(input()).split()
a = []
for i in range(c1):
    a.append(int(c2[i]))
print(garland(a))
#print(garland([7, 0, 9, 0, 5, 0, 15, 0, 0, 1, 17, 0, 11, 19, 0, 0, 3, 0, 13, 0]))
#print(garland([1, 0, 3]))              
#print(garland([0, 5, 0, 2, 3]))
#print(garland([1, 0, 0, 5, 0, 0, 2]))
#print(garland([0, 0, 0, 0, 0]))
#print(garland([0, 2, 0, 4]))
#print(garland([2, 0, 0, 3]))