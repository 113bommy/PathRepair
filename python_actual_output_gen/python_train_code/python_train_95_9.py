c, v0, v1, a, l = [int(j) for j in input().split()]
for i in range(1, 1000000):
    c -= v0
    if i > 1:
        c += 1
    if c <= 0:
        print(i)
        break
    v0 += a
    vo = min(v0, v1)
