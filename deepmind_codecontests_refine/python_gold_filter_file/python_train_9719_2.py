
import math
x,y,z=[int(x) for x in input().split()]
a=math.sqrt(x*y/z)
b=math.sqrt(z*x/y)
c=math.sqrt(z*y/x)
print(int(4*(a+b+c)))
