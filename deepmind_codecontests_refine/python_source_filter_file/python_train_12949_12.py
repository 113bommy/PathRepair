import math
import itertools as it


n, a = int(input()), list(map(int, input().split()))
g = list(it.accumulate(a, math.gcd))[-1]

divs = set()
for d in range(1, int(math.sqrt(g)) + 1):
    if g % d == 0:
        divs = divs.union({d, g // d})

ans = divs.intersection(set(a))
print(0 if len(ans) == 0 else ans.pop())
