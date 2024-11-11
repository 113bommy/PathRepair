n, k, t = (int(x) for x in input().split())
if t >= n:
    print((n + k) % t)
else:
    print(min(k, t))
