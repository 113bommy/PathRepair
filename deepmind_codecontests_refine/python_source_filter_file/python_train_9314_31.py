n,x1,y1 = map(int,input().split())
import math
stormx = []
stormy = []
for i in range(0,n):
    x2,y2 = map(int,input().split())
    stormx.append(x2)
    stormy.append(y2)

def problem5(n,x1,y1,stormx,stormy):
    
    s = set()
    
    for i in range(0,n):
        
        m = slope(x1,y1,stormx[i],stormy[i])
        
        s.add(m)

        print(m)
    print(s)
    print(len(s))


def slope(x1, y1, x2, y2):
    
    y = y2-y1
    x = x2-x1
    
    if x2==x1:
        return 9999
    return (y2-y1)/(x2-x1)

problem5(n,x1,y1,stormx,stormy)


