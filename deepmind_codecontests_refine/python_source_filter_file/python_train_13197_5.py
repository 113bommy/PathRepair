n = int(input())
a = list(map(int, input().split()))
a.sort()

ans = 0
for i in range(1, n):
    ans += a[n-int(i/2)]
print(ans)
