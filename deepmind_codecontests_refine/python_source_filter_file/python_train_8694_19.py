import math
entrada=input().split(" ")
a=int(entrada[0])
b=int(entrada[1])
c=int(entrada[2])
x1=(-b+math.sqrt(b**2-4*a*c))/2*a
x2=(-b-math.sqrt(b**2-4*a*c))/2*a
if(x1>x2):
    print(str('%8.16f'%(x1)))
    print(str('%8.16f'%(x2)))
else:
    print(str('%8.16f'%(x2)))
    print(str('%8.16f'%(x1)))