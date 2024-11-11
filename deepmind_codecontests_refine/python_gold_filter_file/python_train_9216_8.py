import sys

n, a, b, c, d = map(int,sys.stdin.readline().split())

c1 = 0
for x11 in range(n):
    x13 = x11 + 1 - c + b
    x31 = x11 + 1 - d + a
    x33 = x11 + 1 - c - d + a + b
    #print (x11 + 1, x13, x31, x33)
    if x13 >= 1 and x13 <= n and x31 >= 1 and x31 <= n and x33 >= 1 and x33 <= n:
        c1 = c1 + 1
print (c1 * n)
