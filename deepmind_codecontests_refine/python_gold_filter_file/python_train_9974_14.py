from fractions import gcd
n = int(input())
a = list(map(int,input().split()))
l = [0]
r = [0]
ans = 0
for i in range(n-1):
    l.append(gcd(l[i],a[i]))
for i in range(n-1):
    r.append(gcd(r[i],a[n-1-i]))
for i in range(n):
    ans = max(ans,gcd(l[i],r[-i-1]))
print(ans)