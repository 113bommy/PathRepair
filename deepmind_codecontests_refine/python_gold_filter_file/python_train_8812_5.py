n,k,m,d=map(int,input().split())
ans=0
for i in range(1,d+1):
    x=0
    if(n/((i-1)*k+1)<=m):
        x=n//((i-1)*k+1)
    else:
        x=m
    if(x*i>=ans):
        ans=x*i
    #ans=max(ans, min(n/((i-1)*k+1), m)*i)
print(ans)