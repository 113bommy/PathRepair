n, a, b = map(int, input().split())

x = min(a,b)
y = max(a+b-10, 0)

print(x, y)