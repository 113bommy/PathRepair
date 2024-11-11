from collections import Counter
n = int(input())
s = [input() for _ in range(n)]
d = Counter(s)
a = 0
for v in d.values():
  if v>a:
    a = v
for k in d.keys():
  if d[k]==a:
    print(k)