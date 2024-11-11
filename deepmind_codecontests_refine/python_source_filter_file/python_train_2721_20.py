from math import ceil
n=int(input())
x=list(map(int,input().split()))
c=0
d=0
for i in x:
    if i/1>1:
        c=c+1
    if i/(-1)>1:
        d=d+1

if c>n/2:
    print(1)
elif d>n/2:
    print(-1)
else:
    print(0)


    
