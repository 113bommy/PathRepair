R=lambda:[*map(int,input().split())]
x,y,u,v=R()
a=b,c=R(),R()
x1,x2,x3,x4=sorted(b[::2]+c[::2])
y1,y2,y3,y4=sorted(b[1::2]+c[1::2])
if x2 in(b[0],c[0])and y2 in(b[1],c[1]):
    a+=(x1,y2,y3,x4),(x2,y1,x3,y4)
r='YES'
for x1,y1,x2,y2 in a:
 if x1<=x<=u<=x2 and y1<=y<=v<=y2:r='NO';break
print(r)