MOD = 1000000007
ii = lambda :  int(input())
si = lambda :  input()
dgl = lambda : list(map(int, input()))
f = lambda :   map(int, input().split())
il = lambda :  list(map(int, input().split()))
ls = lambda :  list(input())
from collections import *
for _ in range(ii()):
    x,n,m=f()
    while(n>0 or m>0):
        if(x>20 and n>0 or m<=0):
            x=(x//2)+10
            n=n-1
        else:
            x=x-10
            m=m-1
        if(x<=0):
            break
    if(x<=0):
        print("YES")
    else:
        print("NO")