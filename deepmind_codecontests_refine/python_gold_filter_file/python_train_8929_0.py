from collections import Counter

c = Counter(input() for _ in range(int(input())))
m = max(c.values())
for s in sorted(s for s, k in c.items() if k == m): 
  print(s)


