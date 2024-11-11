from math import sin, cos, pi, sqrt
a, b, c = map(int, input().split())
s = a*b*sin(pi*c/180)/2
c = sqrt(a**2 + b**2 -a*b*2*cos(pi*c/180))
h = 2*S/a
print(s)
print(a+b+c)
print(h)
