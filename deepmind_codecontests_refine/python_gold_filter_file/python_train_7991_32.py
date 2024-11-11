n,k=map(int,input().split())
a=list(map(int,input().split()))
ok=max(a)
ng=0
while ok-ng>1:
    mid=(ok+ng)//2
    cnt=0
    for i in range(n):
        num=a[i]
        cnt+=-(-num//mid)-1
    if cnt<=k:
        ok=mid
    else:
        ng=mid
print(ok)