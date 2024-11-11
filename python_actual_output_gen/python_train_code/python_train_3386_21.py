n, x = map(int, input().split())
rpos = 1
ans = 0
for i in range(n):
    l, r = map(int, input().split())
    ans += ((l - rpos) // x) * x
    rpos = l + 1
print(r - ans)
