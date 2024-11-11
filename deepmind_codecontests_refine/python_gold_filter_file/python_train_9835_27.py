n, x = [int(_) for _ in input().split()]
t = 1
c = 0
for m in range(n):
    l, r = [int(_) for _ in input().split()]
    while t <= l:
        t += x
    t -= x
    c += r - t + 1
    t = r + 1
print(c)
