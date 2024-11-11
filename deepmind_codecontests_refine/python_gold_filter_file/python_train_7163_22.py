n,a,b=map(int,input().split())

ans=[0,0]

ans[0]=min(a,b)
ans[1]=max(0,a+b-n)
print(*ans)