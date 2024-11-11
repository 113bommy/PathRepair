s,x1,x2=input().split(' ')
s=int(s)
x1=int(x1)
x2=int(x2)
v1,v2=input().split(' ')
v1=int(v1)
v2=int(v2)
v1=1/v1
v2=1/v2
p,d=input().split(' ')
p=int(p)
d=int(d)
if x1>x2 :
    x1=s-x1
    x2=s-x2
    d=-d
    p=s-p
if p<=x1:
    if d==-1:
        x=p+x1
    else:
        x=x1-p
    t=x/(v1-v2)
    if x1+t*v2<=x2:
        t=t+(x2-x1-t*v2)/v1
    else:
        t=(x2-x1)/v2
else:
    if d==-1:
        x=p-x1
    else:
        x=2*s-p-x1
    t=x/(v1+v2)
    if x1+t*v2<=x2:
        t=min(t+(x2+x1+t*v2)/v1,(x2-x1)/v2)
    else:
        t=(x2-x1)/v2
print(int(t+0.5))