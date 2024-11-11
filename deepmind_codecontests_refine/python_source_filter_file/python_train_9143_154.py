a, b, c, d = map(int, input().split())
t = min(c,d) - max(a,b)
print(max(t, 0))