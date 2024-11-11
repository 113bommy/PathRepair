from itertools import accumulate
from collections import Counter

p = int(input().split()[1])
a = map(int, input())
if 10 % p == 0:
  r = sum(i for i, x in enumerate(a, 1) if x % p == 0)
else:
  a = accumulate(x * pow(10, i, p) for i, x in enumerate(reversed(a), 1))
  c = Counter(x % p for x in a) 
  c[0] += 1
  r = sum(i * (i - 1) // 2 for i in c.values())
print(r)
