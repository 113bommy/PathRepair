# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 11/26/18

"""
import math


f = [0] * 100
for i in range(100):
    f[i] = (4**i-1) // 3


def solve(N, K):
    
    if N < 100 and f[N] < K:
        print('NO')
        return
    
    for i in range(99):
        if f[i] <= K < f[i+1]:
            x = K - f[i]
            a = N - i
            
            if x == 0:
                print('YES {}'.format(a))
                return
                
            edge = 2**(i+1) - 1
            others = (2**i-1) ** 2
            if edge == x:
                print('YES {}'.format(a-1))
                return
            
            ans = a
            if edge < x:
                x -= edge
                ans = a-1

            # split others
            for j in range(a + 1):
                if others * f[j] >= x:
                    print('YES {}'.format(ans))
                    return
            print('NO')
            
            return
    
    print('NO')
    
    
T = int(input())

for ti in range(T):
    N, K = map(int, input().split())
    solve(N, K)