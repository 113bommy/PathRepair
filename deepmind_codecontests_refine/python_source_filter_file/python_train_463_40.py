import math 
def moves(r,x,y,x1,y1):
    st = math.sqrt((x-x1)**2  + (y-y1)**2)
    return math.ceil(st/2*r)
r,x,y,x1,y1 = map(int,input().split())
print(moves(r,x,y,x1,y1))