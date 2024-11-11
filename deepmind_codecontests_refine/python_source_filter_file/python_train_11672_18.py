from math import *
n,m,k,l=map(int,input().split())
if(m>n):
    print(-1)
    exit(0)
re=floor((l+k+m-1)/m)
if(re*m>n):
    print(-1)
    exit(0)
print(re)
