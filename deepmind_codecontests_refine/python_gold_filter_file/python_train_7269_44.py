n,y=map(int,input().split())
y=y/1000
ans=(-1,-1,-1)
for i in range(1+n):
    for j in range(n-i+1):
        if i*10+j*5+(n-i-j)==y and n-i-j>=0:
            ans=(i,j,n-i-j)
print(*ans)
