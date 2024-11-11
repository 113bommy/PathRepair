def dot(a,b):return a[0]*b[0] + a[1]*b[1]
def cross(a,b):return a[0]*b[1] - a[1]*b[0]

q = int(input())
for i in range(q):
    x0,y0,x1,y1,x2,y2,x3,y3 = [int(i) for i in input().split()]
    a = [x1-x0,y1-y0]
    b = [x3-x2,y3-y1]
    if dot(a,b) == 0 : print(1)
    elif cross(a,b) == 0 : print(2)
    else : print(0)