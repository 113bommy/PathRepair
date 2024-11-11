n = int(input())

a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
a.sort()
b.sort()
c.sort()

d = 0
e = 0
ans = 0
for i in b:
    while i > a[min(d,n-1)] and d <= n-1:
        d += 1
    while i >= c[min(e,n-1)] and e < n:
        e += 1
    ans += d*(n-e)

print(ans)