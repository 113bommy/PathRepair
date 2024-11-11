import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

def min(a, b):
    if a < b:
        return a
    return b

def max(a, b):
    if a < b:
        return b
    return a

p = sys.stdin.readline().split()
t = int(p[0])
w = int(p[1])
b = int(p[2])

m = min(w, b)
M = lcm(w, b)

z = int((t // M + 1) * m - 1 - max(m - 1 - t % M, 0))
y = gcd(z, t)
z = z // y
t = t // y
print('{:d}/{:d}'.format(z, t))
