n, x = [int(_) for _ in input().split()]
t = 1
c = t
for m in range(n):
    l, r = [int(_) for _ in input().split()]
    while t <= l:
        t += x
    t -= x
    c += r - t
    t = r
print(c)
