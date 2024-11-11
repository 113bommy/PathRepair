def solve(a,n):
    if n==1:
        return 0
    a.sort()
    minn = 1e9+239
    for i in range(1,n):
        minn = min(a[i],a[i+n-1])
    ans = min((a[2*n-1]-a[0])*minn , (a[n-1]-a[0])*(a[2*n-1]-a[n]))
    return ans

n = int(input())
a = list(map(int,input().split()))
pt = solve(a,n)
print(pt)