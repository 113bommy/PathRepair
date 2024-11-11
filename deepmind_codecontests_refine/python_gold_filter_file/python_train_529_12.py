n, l, a = map(int, input().split())
ans, t0 = 0, 0
for i in range(n):
    t, li = map(int, input().split())
    ans += (t - t0) // a
    t0 = li + t
ans += (l - t0) // a
print(ans)