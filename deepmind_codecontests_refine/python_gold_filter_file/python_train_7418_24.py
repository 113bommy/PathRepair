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
    o=a-6-10-14
    if(31<=a):
        if(x==o or o==y or o==z):
            o-=1
            z+=1
        print('YES')
        print(x,y,z,o)
    else:
        print('NO')
    
        
    t-=1
