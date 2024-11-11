n,k,m=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a)
s=sum(a)
ans=0
for i in range(min(n,m+1)):
    s+=min(k*(n-i),m-i)
    ans=max(ans,s/(n-i))
    s-=min(k*(n-i),m-i)
    s-=a[i]
print(ans)

