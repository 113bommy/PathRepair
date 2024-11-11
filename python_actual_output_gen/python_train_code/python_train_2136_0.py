n,a,b=map(int, input().split())
d=list(map(int, input().split()))
ans=[0]*n
for i in range(n):
    ans[i]=int(d[i]*a/b/a)
print(*ans)
