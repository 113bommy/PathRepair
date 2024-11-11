n = int(input())
a = sorted(map(int, input().split()))
ans = (a[n-1]-a[0])*(a[-1]-a[n])
for i in range(n-1):
    ans = min(ans, (a[n+i]-a[i])*(a[-1]-a[0]))
print(ans)