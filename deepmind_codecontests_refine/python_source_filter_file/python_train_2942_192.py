import math

t = int(input())

while t!=0:
    n = int(input())
    if n==3:
        print (2)
    elif n==1:
        print (1)
    else:
        print (math.floor(n/2))
    t-=1
    
    
