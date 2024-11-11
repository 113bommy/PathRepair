import math
n,x,y=map(int,input().split())
l=list(map(int,input().split()))
if(x>y):
    print(n)
else:
    count=0
    for i in range(n):
        if(l[i]<x):
            count+=1
    print(math.ceil(count/2))