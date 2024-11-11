import sys
from collections import deque

input = sys.stdin.readline

n,k = map(int,input().split())
a = list(map(int,input().split()))

def possible(x):
    # can we find a subseq s such that cost(s) = x?
    L = [0]*n
    B = [-1]*n
    prev = deque(maxlen=2)

    for i in range(n):
        if a[i] > x:
            continue
        
        L[i] = 1
        B[i] = i
        for j in prev:
            if j+1 == i:
                continue
            
            if 1+L[j] > L[i]:
                B[i] = B[j]
                L[i] = 1+L[j]
        
        prev.append(i)

    for i in range(n):
        if B[i] == -1:
            continue

        length = L[i]*2 - 1
        if B[i] >= 1:
            length += 1
        if i+1 < n:
            length += 1
        if length >= k:
            return True
    return False

lo,hi = 0,max(a)

while lo+1 < hi:
    mid = (lo+hi) // 2
    if possible(mid):
        hi = mid
    else:
        lo = mid

print(hi)
