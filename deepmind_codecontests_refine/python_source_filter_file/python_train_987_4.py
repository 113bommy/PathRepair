n,k = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(n)]
a.sort()
s = 0
ans = 0
r = 0
for l in range(n):
    while r<n and a[r][0]-a[l][0]<=k:
        s+=a[r][1]
        r+=1
    ans=max(ans,s)
    s-=a[l][1]
print(ans)