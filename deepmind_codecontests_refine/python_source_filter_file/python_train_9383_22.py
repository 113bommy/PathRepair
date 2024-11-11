n,k,m=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a)
s=sum(a)
if m<=k*n:
    ans=(s+m)/n
else:
    ans=(s+k*n)/n

for i in range(min(n-1,m+1)):
    s=s-a[i]
    m-=1
    if m<=k*(n-i-1):
        t=(s+m)/(n-i-1)
    else:
        t=(s+k*(n-i-1))/(n-i-1)
    if t>ans:
        ans=t
print(ans)