n,k=map(int,input().split())
wd=[]
for i in range(n):
    wd.append(list(map(int,input().split())))
    
ok=wd[0][0]+k*wd[0][1]+2
ng=0

while ok-ng>1:
    m=(ok+ng)//2
    z=0
    for i in range(n):
        if wd[i][0]<m:
            z+=(m-wd[i][0])//wd[i][1]+1
    if z>=k:
        ok=m
    else:
        ng=m
print(ok)