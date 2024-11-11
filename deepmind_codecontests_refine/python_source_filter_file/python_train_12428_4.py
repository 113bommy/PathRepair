n=int(input())
a=list(map(int,input().split()))
ans=0
a.sort()
for i in range(n):
    if a[i]<=n:
        ans+=(i+1)-a[i]
    else:
        ans+=a[i]-i-1
print(ans)
             

