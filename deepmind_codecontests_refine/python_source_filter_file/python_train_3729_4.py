N, M = map(int, input().split())
PY = [tuple(map(int, input().split())) for _ in range(M)]
sPY = sorted(PY, key=lambda py: py[1])

i = 1
bp = 1
d = {}
for p, y in sPY:
    if p != bp:
        i = 1
        bp = p
    d[y] = i
    i += 1

for p, y in PY:
    print("{0:06}{1:06}".format(p, d[y]))