from operator import or_
from itertools import accumulate
_ = input()
l = [*map(int, input().strip().split())]
lx = [0, *accumulate(l, or_)]
rx = [*reversed(list(accumulate(reversed(l), or_))), 0]
_, idx = max((x & ~(a | b), i) for i, (x, a, b) in enumerate(zip(l, lx, rx[1:])))
print(*l[idx - len(l): idx])