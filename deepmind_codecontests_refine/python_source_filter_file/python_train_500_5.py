rom collections import Counter

s = input().strip()
c = Counter(s)
v = list(c.values())
if max(v) - min(v) > 1: 
  print("NO")
else:
  print("YES")