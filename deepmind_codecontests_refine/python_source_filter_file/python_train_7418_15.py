#rOkY
#FuCk

################################## kOpAl #######################################
import math
def ans(a):
    for i in range(2,int(math.sqrt(a))+1,1):
        if(a%i==0):
            return False
    return True
t=int(input())
while(t>0):
    a=int(input())
    
    x=6
    y=10
    z=14
    o=a-x-y-z
    if(31<=a):
        if(x==o or y==z or o==z):
            o-=1
            z+=1
        print('YES')
        print(x,y,z,o)
    else:
        print('NO')
    
        
    t-=1
