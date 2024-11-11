import bisect
n,m,v,p=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
ok=n#idx
ng=-1
def solve(x):
    if bisect.bisect_right(l,l[x])>=n-p+1:
        return 1
    lx=l[x]+m
    lxi=bisect.bisect_right(l,lx)-1
    if lxi<=n-p-1:
        return 0
    #n-p-1<lxi
    f=0
    for i in range(n):
        if i<=x or i>n-p:
            f+=m
            continue         
        else:
            f+=min(lx-l[i],m)
    if f>v*m:
        return 2
    else:
        return 0
#for i in range(n):
    #print(solve(i))
while ok-ng>1:
    x=(ok+ng)//2
    if solve(x):
        ok=x
    else:
        ng=x
    #print(x)
print(n-ok)