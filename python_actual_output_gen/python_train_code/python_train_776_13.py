n,m=map(int, input().split())
a=list(map(int, input().split()))
a.sort()
if n==m:
    print(a[-1]-a[0])
else:
    ans=float('inf')
    for i in range(0,m-n):
        ans=min(ans,a[n+i-1]-a[i])
    print(ans)
