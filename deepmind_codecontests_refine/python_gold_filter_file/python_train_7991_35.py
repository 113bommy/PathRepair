from math import ceil
n,k=map(int,input().split())
lst=list(map(int,input().split()))
ng=0
ok=10**9+1
while ok-ng>1:
    mid=(ok+ng)//2
    tmp=0
    for i in range(n):
        tmp+=ceil(lst[i]/mid)-1
    if tmp>k:
        ng=mid
    else:
        ok=mid
print(ok)