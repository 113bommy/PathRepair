def dot(a,b):
    return a[0]*b[0] + a[1]*b[1]

x1,y1,x2,y2 = [int(i) for i in input().split()] 
q = int(input())
for i in range(q):
    x,y = [int(i) for i in input().split()]
    a = [x2-x1,y2-y1]
    b = [x-x1,y-y1]
    co = dot(a,b) / dot(a,a)
    print(a[0]*co,a[1]*co)