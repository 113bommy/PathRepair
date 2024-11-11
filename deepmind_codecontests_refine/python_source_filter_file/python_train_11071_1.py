import math
def intersect(r1,R1,r):
    global d
    if d+r<=R1:
        return 1
    elif r+R1<=d:
        return 1
    elif d+R1<=r:
        return 1
    return 0

x1,y1,r1,R1=map(int,input().split())
x2,y2,r2,R2=map(int,input().split())
d=math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
print(intersect(r1,R1,r2)+intersect(r1,R1,R2)+intersect(r2,R2,r1)+intersect(r2,R2,R1))



  

            
    
    
