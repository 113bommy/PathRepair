
from collections import Counter

t=int(input())
for _ in range(t):
    n=int(input())
    s=list(map(int,input().split()))
    d=dict(Counter(s))
    ma=0
    mb=0
    mbvisited=False
    for x in range(101):
        if x not in d:
            ma=x
            if mbvisited==False:
                mb=x
            break
        if d[x]==1 and mbvisited==False:
            mb=x
            mbvisited=True
    print(ma+mb)
