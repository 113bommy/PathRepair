def get_center_and_radius(x1, y1, x2, y2, x3, y3):
    if (y2-y1)*(x3-x1)==(y3-y1)*(x2-x1):
        return -1, -1, -1
        
    d = 2*(x1-x2)*(y1-y3)-2*(x1-x3)*(y1-y2)
    cx = ((x1**2-x2**2+y1**2-y2**2)*(y1-y3)-(x1**2-x3**2+y1**2-y3**2)*(y1-y2))/d
    cy = ((x1**2-x3**2+y1**2-y3**2)*(x1-x2)-(x1**2-x2**2+y1**2-y2**2)*(x1-x3))/d
    r2 = (x1-cx)**2+(y1-cy)**2
    
    return cx, cy, r2
    
def is_inclusive(cx, cy, r2):
    for xi, yi in xy:
        if (xi-cx)**2+(yi-cy)**2>r2:
            return False
    
    return True
    
N = int(input())
xy = [tuple(map(int, input().split())) for _ in range(N)]
R2 = 10**18

for i in range(N):
    for j in range(i+1, N):
        xi, yi = xy[i]
        xj, yj = xy[j]
        cx, cy = (xi+xj)/2, (yi+yj)/2
        r2 = (cx-xi)**2+(cy-yi)**2
        
        if is_inclusive(cx, cy, r2):
            R2 = min(R2, r2)

for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            xi, yi = xy[i]
            xj, yj = xy[j]
            xk, yk = xy[k]
            cx, cy, r2 = get_center_and_radius(xi, yi, xj, yj, xk, yk)
            
            if cx==-1:
                continue
            
            if is_inclusive(cx, cy, r2):
                R2 = min(R2, r2)

print(R2**0.5)