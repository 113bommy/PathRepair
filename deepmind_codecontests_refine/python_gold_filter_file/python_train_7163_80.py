n, a, b = map(int, input().split())

x = min(a,b)
y = max(a+b-n, 0)

print(x, y)