from string import ascii_lowercase as a
from itertools import cycle


n, k = map(int, input().split())
c = cycle(a)
for i in range(n):
  print(next(c), end='')