import math

a, b, c, d, e, f = map(int, input().split(" "))
x = b + a + c
y = d + c + e
z = f + e + a
s = x*x - a - c - e
print(int(s)) 