s=input()
l=[]
l=list(map(int,s.split()))
R=l[0]
r=0
x1=l[1]
y1=l[2]
x2=l[3]
y2=l[4]
d=(((x2-x1)**2)+((y2-y1)**2))**0.5
if(d>=R and d!=0):
    r=(R)
    xa=x1
    ya=y1
if(d<R and d!=0):
    r=(R+d)/2
    xa=(x2+(((R+d)*x1)-R*x2)/d)/2
    ya=(y2+(((R+d)*y1)-R*y2)/d)/2
if(d==0):
    r=R/2
    xa=0.0
    ya=5.0
print(xa)
print(ya)
print(r)
