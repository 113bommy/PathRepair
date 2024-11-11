import os, sys, atexit
from io import BytesIO

sys.stdout = BytesIO()
_write = sys.stdout.write
sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

r, n = map(int, input().split())
a = [[0, 1, 1]] + [list(map(int, input().split())) for _ in range(n)]
mem = [0] * (n + 1)
ma = [0] * (n + 1)

for i, (t, x, y) in enumerate(a[1:], 1):
    ix = i - 1
    cur = -(1 << 30)
    all = t - (max(x, 500 - x) + max(y, 500 - y))

    while ix > -1:
        t1, x1, y1 = a[ix]
        if mem[ix] > cur and abs(x - x1) + abs(y - y1) <= t - t1:
            cur = mem[ix]

        if a[ix][0] <= all:
            if ma[ix] > cur:
                cur = ma[ix]
            break
        ix -= 1
    mem[i] = cur + 1
    ma[i] = max(ma[i - 1], mem[i])

print(ma[-1])
