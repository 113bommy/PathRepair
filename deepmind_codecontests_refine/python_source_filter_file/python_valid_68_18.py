import math
x=int(input())
for i in range (x):
    y=int(input())
    z=math.trunc(math.sqrt(y))
    w=z+1  
    if z*z==y:
        print(z,1)    
    elif y>z*z+z:
        v=z+1
        u=w*w-y+1
        print(v,u)
    else:
        u=z+1
        v=z*z+w-y
        print(v,u)
    