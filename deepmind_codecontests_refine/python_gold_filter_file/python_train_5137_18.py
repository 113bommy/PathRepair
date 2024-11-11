import math as m


s, t = input(), input()
a, b = len(s), len(t)

g = m.gcd(a, b)
divs = {1, g}

for d in range(2, int(m.sqrt(g)) + 1):
    if g % d == 0:
        divs.add(d)
        divs.add(g // d)

cnt = 0
for d in sorted(divs, reverse=True):
    if s[:d] * (a // d) == s and s[:d] * (b // d) == t:
        cnt += 1

print(cnt)
