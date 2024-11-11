def check(List,mid):
    tmp=0
    for l in List:
        tmp+=(-(-l//mid)-1)
    return tmp

n,k=map(int,input().split())
a=list(map(int,input().split()))
lo=0
hi=max(a)+1

while hi - lo > 1:
    mid=(lo+hi)//2
    if check(a,mid)<=k:
        hi=mid
    else:
        lo=mid

print(hi)