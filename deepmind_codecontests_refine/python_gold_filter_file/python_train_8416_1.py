N,x = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(1,N):
    s = a[i-1]+a[i]
    if s > x:
        ans += s-x
        a[i] = max(0,x-a[i-1])
print(ans)