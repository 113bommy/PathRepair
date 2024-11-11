x, y = map(int, input().split())
m = max(x, y)
n = min(x, y)
print(m, (m - n) // 2)