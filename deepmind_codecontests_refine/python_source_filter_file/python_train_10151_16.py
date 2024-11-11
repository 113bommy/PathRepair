from fractions import gcd

t, w, b = map(int, input().split())
lcm = w / gcd(w, b) * b
m = min(w, b)
a = m - 1 + (t // lcm - 1) * m + min(m, t % lcm + 1)
g = gcd(a, t)
print("%d/%d" % (a / g, t / g))
