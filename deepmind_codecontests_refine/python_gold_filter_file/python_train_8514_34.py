#from string import ascii_lowercase
from bisect import bisect_right
s = input()
t = input()
p = {c: [] for c in s}
for x, c in enumerate(s):
    p[c].append(x)
z = 0
l = -1
for c in t:
    if c not in p:
        print(-1)
        break
    x = bisect_right(p[c], l)
    if x == len(p[c]):
        x = 0
        z += 1
    l = p[c][x]
else:
    print(z * len(s) + l + 1)
