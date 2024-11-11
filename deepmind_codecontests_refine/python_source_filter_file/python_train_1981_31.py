import math
a,b,c,d = map(float, input().split())
t = pow(a-b,2) + pow(b-d,2)
print(math.sqrt(t))