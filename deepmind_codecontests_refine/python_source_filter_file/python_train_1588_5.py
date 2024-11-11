import math 
t=int(input())
while t:
    t-=1 
    
    n=int(input())
    x=1/math.sin((math.pi)/(2*n))  
    if n==2:
        print('1.000000000')
    else:
        print('%.9f'%x)
