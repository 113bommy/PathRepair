from math import *
n = int(input())
l = list(map(int, input().split()))
if n==1:
    print(1, 1)
    print(l[0])
    print(1, 1)
    print(-l[0])
    print(1, 1)
    print(-l[0])
else:
    print(1, n-1)
    for i in range(n-1):
        print(l[i]*(n-1),end=' ')
    print()
    print(n, n)
    print(l[n-1])
    print(1, n)
    for i in range(n):
        print(-l[i]*n,end=' ')
    print()

