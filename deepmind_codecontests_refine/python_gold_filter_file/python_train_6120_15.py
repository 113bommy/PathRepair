N,K = map(int,input().split())
XYC = [list(map(int,input().split())) for _ in [0]*N]
eps = 1e-7
def f(x,y,t):
    ret = 0
    for X,Y,C in XYC:
        if ((x-X)**2+(y-Y)**2)<=(t/C)**2+eps: ret += 1
    return ret

def get_cross_section(x1,y1,r1,x2,y2,r2):
    d = ((x1-x2)**2+(y1-y2)**2)**0.5
    X = (d*d+r1*r1-r2*r2)/(2*d)
    Y = max(0,(r1*r1-X*X))**0.5
    dx = (x2-x1)/d
    dy = (y2-y1)/d
    ret = [(x1+X*dx+Y*dy,y1+X*dy-Y*dx)]
    if Y>0 : ret.append((x1+X*dx-Y*dy,y1+X*dy+Y*dx))
    return ret
def check(t):
    kouho = []
    for i in range(N):
        x1,y1,c1 = XYC[i]
        kouho.append((x1,y1))
        for j in range(i+1,N):
            x2,y2,c2 = XYC[j]
            tmp = get_cross_section(x1,y1,t/c1,x2,y2,t/c2)
            for tmp2 in tmp:
                kouho.append(tmp2)
    for tmp in kouho:
        if f(tmp[0],tmp[1],t) >= K:return True
    return False

l=0
r=1000000
#for _ in range(100):
while abs(r-l)>1e-7:
    i = (l+r)/2
    if check(i):
        r = i
    else:
        l = i
print(r)