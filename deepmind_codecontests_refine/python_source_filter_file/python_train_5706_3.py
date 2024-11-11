n=int(input())
r,l,u,d=[[] for _ in range(4)]
cx_max,cx_min,cy_max,cy_min=[None for _ in range(4)]

for i in range(n):
    x,y,s=input().split()
    x,y=int(x),int(y)
    if s=='R':
        r.append(x)
        if cy_max==None or cy_min==None:
            cy_max,cy_min=y,y
        cy_max,cy_min=max(cy_max,y),min(cy_min,y)
    if s=='L':
        l.append(x)
        if cy_max==None or cy_min==None:
            cy_max,cy_min=y,y
        cy_max,cy_min=max(cy_max,y),min(cy_min,y)

    if s=='U':
        u.append(y)
        if cx_max==None or cx_min==None:
            cx_max,cx_min=x,x
        cx_max,cx_min=max(cx_max,x),min(cx_min,x)
    if s=='D':
        d.append(y)
        if cx_max==None or cx_min==None:
            cx_max,cx_min=x,x
        cx_max,cx_min=max(cx_max,x),min(cx_min,x)
        
r.sort()
l.sort()
u.sort()
d.sort()

T=[0,10**9]
for j in r+l:
    if cx_max!=None:
        T.append(abs(j-cx_min))
        T.append(abs(j-cx_max))
for j in u+d:
    if cy_max!=None:
        T.append(abs(j-cy_min))
        T.append(abs(j-cy_max))

try:
    for i in [r[0],r[-1]]:
        for j in [l[0],l[-1]]:
            T.append(abs(i-j)/2)
except:
    0
try:
    for i in [u[0],u[-1]]:
        for j in [d[0],d[-1]]:
            T.append(abs(i-j)/2)
except:
    0

def val(t):
    xmax,xmin,ymax,ymin=[[] for _ in range(4)]
    if u:
        ymax.append(u[-1]+t)
        ymin.append(u[0]+t)
    if d:
        ymax.append(d[-1]-t)
        ymin.append(d[0]-t)
    if cy_max!=None:
        ymax.append(cy_max)
        ymin.append(cy_min)
        
    if r:
        xmax.append(r[-1]+t)
        xmin.append(r[0]+t)
    if l:
        xmax.append(l[-1]-t)
        xmin.append(l[0]-t)
    if cx_max!=None:
        xmax.append(cx_max)
        xmin.append(cx_min)
    
    Y=max(ymax)-min(ymin)
    X=max(xmax)-min(xmin)
    return X*Y

ans=0
for t in T:
    ans=min(ans,val(t))
    
print(ans)