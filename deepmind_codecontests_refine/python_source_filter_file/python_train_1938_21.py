from math import sqrt
r, d = map(int, input().split())
n = int(input())
ans = 0
for i in range(n):
    x, y, r1 = map(int, input().split())
    d = sqrt(x ** 2 + y ** 2)
    if d >= r - d + r1 and d <= r - r1:
        ans += 1
print(ans)