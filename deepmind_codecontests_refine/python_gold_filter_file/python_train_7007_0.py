from collections import Counter
from sys import stdin

input = stdin.readline

for _ in range(int(input())):
    n, l , r = map(int, input().split())
    arr = list(map(int , input().split()))

    if l > r:
        l, r = r, l
        arr = arr[::-1]
    
    left = [0]*n
    right = [0]*n
    
    for i in range(n):
        if i <  l:
            left[arr[i] - 1] += 1
        else:
            right[arr[i] - 1] += 1
        
    pairs = 0
    ep = 0
    for i in range(n):
        m = min(left[i], right[i])
        pairs += m
        left[i] -= m
        right[i] -= m
        ep += right[i]//2

    # Total number of pairs wanted
    want = n//2 
    rem = want - pairs
    cost = rem + max(0, (r-want)-ep)
    print(cost)
    # print(lefts, rights)