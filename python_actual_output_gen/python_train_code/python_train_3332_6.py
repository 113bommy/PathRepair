def is_sqr(x):
  y = 1
  while y**2 < x:
    y += 1
  return y**2 == x

from itertools import combinations
n = input()
ans = 100
for r in range(1, len(n)):
  for item in combinations(n, r):
    #print(int(''.join(item)))
    if is_sqr(int(''.join(item))) and item[0] != '0':
      ans = min(ans, len(n) - len(item))
print(ans if ans != 100 else -1)
