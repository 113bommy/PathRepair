def dot(u,v):
    return(u[0]*v[0] + u[1]*v[1])

def solve(v):
    eps = 1e-10
    xa,ya,xb,yb,xc,yc,xd,yd = v
    if abs(dot( (xb-xa, yb-ya), (xd-xc, yd-yc)) ) < eps:
        return(True)
    else:
        return(False)

while True:
    try:
        v = map(float, input().strip().split())
        if solve(v):
            print("YES")
        else:
            print("NO")
    except EOFError:
        break