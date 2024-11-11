n,k=map(int,input().split())
l=list(map(int,input().split()))
mx=t=sum(l[:k])
ans=1
for i in range(k,n):
    t=t-l[i-k]+l[k]
    if t<mx:
        ans=i-k+1
        mx=t
print(ans)