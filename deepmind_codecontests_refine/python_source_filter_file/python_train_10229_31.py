import math
tc=int(input())
for ctr in range(tc):
    a,b,n=map(int,input().split())
    a,b=min(a,b),max(a,b)
    steps=0
    while 1:
        a,b=b,a+b
        steps+=1
        if a>=n or b>=n:
            print(steps)
            break
