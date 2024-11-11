import math
a,b, A = map(float, input().split())

h = b*math.sin(math.radians(A))
S = a*h*0.5
L = a + b + math.sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*math.cos(math.radians(A)))

print(h)
print(S)
print(L)
