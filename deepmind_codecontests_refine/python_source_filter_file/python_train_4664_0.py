x, y = map(int, input().split())
ans = 0
if x <= 3:
    ans += 400_000 - x * 100_000
if y <= 3:
    ans += 400_000 - y * 100_000
if x == y == 1:
    ans += 400_000
print(ans)
