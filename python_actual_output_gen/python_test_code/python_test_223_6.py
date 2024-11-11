n, v = [int(i) for i in input().split()]
v0 = 0
i = 1
d = 0
if n > v:
    while v0 < n - i:
        d += i * (v - v0)
        v0 += v - v0
        v0 -= 1
        i += 1
else:
    d = n
print(d)
