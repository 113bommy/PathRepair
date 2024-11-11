c, v0, v1, a, l = input().split()
c, v0, v1, a, l = [int(c), int(v0), int(v1), int(a), int(l)]

d, r = 1, v0
while r < c:
    r += min(v0 + a - l, v1)
    d += 1
print(d)
