from bisect import *
n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
if(k==0):
    if(l[0]!=1):
        print(1)
    else:
        print(-1)
    exit()
if(k==n):
    print(l[-1])
    exit()
else:
    if(l[k-1]<l[k]):
        print(l[k-1]+1)
    else:
        print(-1)