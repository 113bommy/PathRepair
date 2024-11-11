n, a, b, c, d = (int(x) for x in input().split())
l = min(a,d) + min(b,c)
h = max(a,d) + max(b,c)
print(max(0, n * (n - (h-l))))
