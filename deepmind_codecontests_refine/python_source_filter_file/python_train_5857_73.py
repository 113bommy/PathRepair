import math

t = int(input())

for _ in range(t):
    n,r = map(int,input().split())
    if r==1:
        print(1)
        continue
    if n < r:
        n-=1
        print(((n*(1+(n)))//2)+1)
    else:
        print((r*(1+r))//2)