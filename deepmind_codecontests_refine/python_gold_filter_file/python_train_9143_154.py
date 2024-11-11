a, b, c, d = map(int, input().split())

t = min(b, d) - max(a, c)

print(max(0, t))