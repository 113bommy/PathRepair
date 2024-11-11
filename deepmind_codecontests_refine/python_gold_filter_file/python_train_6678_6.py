from sys import stdin
import math
from collections import defaultdict

input = stdin.readline

# n, k = map(int, input().split(" "))
# l = list(map(int, input().split(" ")))

n = int(input())
l = list(map(int, input().split(" ")))
if n ==1:
    print(0)
else:
    d = defaultdict(int)
    d_ind = defaultdict(int)
    for i in range(n):
        d_ind[l[i]] = i
        d[l[i]]+=1
    k = max(d, key=d.get)
    start = d_ind[k]
    print(n - d[k])
    for i in range(start, n):
        if l[i]>k:
            print(2,i+1, i)
        if l[i]<k:
            print(1, i+1,i)
    for i in range(start, -1, -1):
        if l[i]>k:
            print(2, i+1,i+2)
        elif l[i]<k:
            print(1, i+1, i+2)