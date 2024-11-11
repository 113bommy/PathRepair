from math import sqrt
a,b,c= map(int,input().split())
i = sqrt((a*b)/c)
j = sqrt((b*c)/a)
k = sqrt((c*a)/b)

print(int(4*(i + j + k)))