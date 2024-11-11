import bisect

n,m,k = map(int,input().split())

x,s = map(int,input().split())

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
a.append(x)
b.append(0)
ans = n*x
for i in range(m):
    if b[i] > s:
        continue
    if b[i] + d[0] > s:
        ans = min(ans,n*a[i])
        continue
    t = bisect.bisect_right(d,s-b[i])-1
    ans = min(ans,(n-c[t])*a[i])
print(ans)