n,m = map(int, input().split())
ls = [list(map(int, input().split())) for i in range(n)]
ans=0
for i in range(m):
    minop=n
    mls = [0]*n
    for j in range(n):
        if ls[j][i]%m==(i+1)%m:
            target=ls[j][i]//m
            if i==m-1:
                target-=1
            if target>=n:
                break
            if j>=target:
                shift=j-target
            else:
                shift=n-(target-j)
            mls[shift]+=1
    for j in range(n):
        minop=min(minop,j+n-mls[j])
    ans+=minop
print(ans)

