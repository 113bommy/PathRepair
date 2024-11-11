MOD = 1000000007
ii = lambda :  int(input())
si = lambda :  input()
dgl = lambda : list(map(int, input()))
f = lambda :   map(int, input().split())
il = lambda :  list(map(int, input().split()))
ls = lambda :  list(input())
from collections import *
for _ in range(ii()):
    n=si()
    l=int(n[0])-1
    p=len(n)-1
    print(l*10 +(p*(p+1))//2)