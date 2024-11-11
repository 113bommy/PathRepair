from collections import Counter

n,k = map(int, input().split())
a = input().split()
c = Counter(a)
t = len(c) - k
r = 0

if t > 0:
    serial = c.most_common[-t:]
    for s in serial:
        r += s[1]

print(r)