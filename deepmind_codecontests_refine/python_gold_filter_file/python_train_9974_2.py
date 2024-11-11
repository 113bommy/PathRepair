n = int(input())
a = list(map(int,input().split()))

from fractions import gcd
l,r = [0]*(n+1),[0]*(n+1)
for i in range(n):
    l[i+1] = gcd(l[i],a[i])
    r[n-i-1] = gcd(r[n-i],a[n-i-1])

ans = 1
for i in range(n):
    g = gcd(l[i],r[i+1])
    ans = max(ans,g)
print(ans)