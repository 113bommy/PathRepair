n = int(input())
a = [int(input()) for _ in range(n)]

ans, tmp, flag = 0, 0, (a[0] > 0)
for i in range(n - 1, 0, -1):
    if a[i] - a[i - 1] > 1:
        flag = True
    elif tmp != a[i]:
        ans += a[i]
    tmp = max(a[i] - 1, 0)
else:
    print(-1 if flag else ans)
