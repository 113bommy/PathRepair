n, d = map(int, input().split())
t = list(map(int, input().split()))
ans = d - sum(t)
if ans - 10 * (n - 1) >= 0:
    print(ans // 5)
else:
    print(-1)
