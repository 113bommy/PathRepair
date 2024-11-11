n,k=list(map(int,input().split()))
alst=list(map(int,input().split()))

ok=max(alst)
ng=0

while abs(ok-ng)>1:
    cen=(ok+ng)//2

    cnt=0

    for a in alst:
        cnt+=(a+cen-1)//cen-1

    if cnt<=k:
        ok=cen
    else:
        ng=cen

print(ok)