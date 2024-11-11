from math import *
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    max_diff = 0
    for i in range(1,n):
        if a[i]<a[i-1]:
            max_diff = max(max_diff,a[i-1]-a[i])
            a[i] = a[i-1]
    if max_diff==0:
        print(0)
    else:

        print(ceil(log2(max_diff))+1)
