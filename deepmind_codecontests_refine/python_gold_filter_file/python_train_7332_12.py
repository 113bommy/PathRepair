import sys
import math

n, s = list(map(int, input().split()))
a = []
for x in range(n):
    x, y, k = list(map(int, input().split()))
    r = math.sqrt(x ** 2 + y ** 2)
    a.append((r, k))
a = sorted(a)
for i in range(n):
    if s < 1000000:
        s += a[i][1]
    else:
        print(a[i - 1][0])
        sys.exit()
if s >= 1000000:
    print(a[-1][0])
else:
    print(-1)
