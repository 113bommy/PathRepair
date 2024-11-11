import math

m, d = map(int, input().split())
n = int(input())
count = 0
for i in range(n):
    x, y, r = map(int, input().split())
    le = math.sqrt(x * x + y * y)
    if d <= le - r and le + r <= m:
        count += 1

print(count)
