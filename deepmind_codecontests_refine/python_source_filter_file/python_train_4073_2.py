# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 11/3/18

"""


N, M, K = map(int, input().split())

A = [int(x) for x in input().split()]


def check(val):
    if val == 0:
        return True
    
    totalBox = 1
    currentBox = K
    for i in range(len(A)-val, len(A)):
        if currentBox >= A[i]:
            currentBox -= A[i]
        else:
            totalBox += 1
            currentBox = K - A[i]
        if totalBox > M:
            return False
    
    return totalBox <= M
    
    

l, h = 0, N+1
while l <= h:
    m = (l + h) // 2
    
    if check(m):
        l = m + 1
    else:
        h = m - 1

print(h)