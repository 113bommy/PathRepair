from math import hypot

R, d = map(int, input().split())
n = int(input())

ans = 0
for i in range(n):
    x, y, r = map(int, input().split())
    if R - d <= max(0, hypot(x, y) - r / 2) and hypot(x, y) + r / 2 <= R:
        ans += 1

print(ans)
