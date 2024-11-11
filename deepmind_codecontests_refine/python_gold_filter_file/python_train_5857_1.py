import math
t = int(input())
for _ in range(t):
    n,r = map(int,input().split())
    A = min(n,r)
    Sum = (A*(A+1))//2
    if (n<=r):
        print(Sum-n+1)
    else:
        print(Sum)