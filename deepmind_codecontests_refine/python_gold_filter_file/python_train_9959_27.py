n,w = map(int, input().split())
a = list(map(int, input().split()))

from itertools import accumulate
b = list(accumulate(a))
c1, c2 = max(b), min(b)

if c1 < 0:
    c1 = abs(c2)
elif c2 < 0:
    c1, c2 = c1-c2, 0
if c1 > w:
    print(0)
else:
    print(w - c1+1)
