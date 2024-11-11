input()
a = input()
s = []
for c in a:
 if not s or s[-1][0] != c:
  s.append([c, 1])
 else:
  s[-1][1] += 1
s2 = sorted(s, key=lambda x: x[1])
delta = 0
if s2[-1][1] >= 3 or len(s2) > 1 and s2[-2][1] >= 2:
 delta = 2
elif s[-1][1] >= 2:
 delta = 1
print(len(s) + delta)