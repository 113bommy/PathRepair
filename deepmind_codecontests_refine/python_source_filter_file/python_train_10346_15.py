n,k=map(int,input().split())
ans=-100000000
for _ in range(n):
    f,t=map(int,input().split())
    if t>k:
        ans=max(ans,f-t+k)
    else:
        ans=max(ans,f)
print(ans)