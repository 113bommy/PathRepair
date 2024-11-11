import math
a, b, c = map(int, input().split())
y=math.sqrt(((a*b)/c))
z=b/y
x=a/y
print((x+y+z)*4)