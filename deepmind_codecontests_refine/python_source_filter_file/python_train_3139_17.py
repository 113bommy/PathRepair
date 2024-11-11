from functools import reduce

mi = lambda: [int(i) for i in input().split()]
flat = lambda l: reduce(lambda a, b: a + b, l)

h, n = mi()
d = mi()

if n == 1:
    if d[0] >= 0:
        print(-1)
    else:
        print((h - d[0] - 1) // (-d[0]))
    exit(0)

changes = [0] * n
changes[0] = -d[0]
for i in range(1, n):
    changes[i] = changes[i] - d[i]
# changes = [-sum(d[0:i]) for i in range(1, n + 1)]

ch = sum(d)
bch = max(changes)

if bch >= h:
    r = 0
    for i in d:
        h += i
        r += 1
        if h <= 0:
            break
    print(r)
    exit(0)

if ch >= 0:
    print(-1)
    exit(0)

r = 0

rounds = (h - bch - ch - 1) // (-ch)
h += rounds * ch
r += rounds * n

for i in d:
    h += i
    r += 1
    if h <= 0:
        break
print(r)

# print(bch)
