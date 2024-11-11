import math

def intersectSeg( pt1, pt2, ptA, ptB, interge=False):
    
    """ this returns the intersection of two segment (pt1,pt2) and (ptA,ptB)
        
        returns a tuple: (xi, yi, valid, r, s), where
        (xi, yi) is the intersection
        r is the scalar multiple such that (xi,yi) = pt1 + r*(pt2-pt1)
        s is the scalar multiple such that (xi,yi) = pt1 + s*(ptB-ptA)
            valid == 0 if there are 0 or inf. intersections (invalid)
            valid == 1 if it has a unique intersection ON the segment    """

    def is_interge(x):
        if abs(round(x) - x) < 0.0000001:
            return True
        return False
    
    DET_TOLERANCE = 0.00000001

    # the first line is pt1 + r*(pt2-pt1)
    # in component form:
    x1, y1 = pt1;   x2, y2 = pt2
    dx1 = x2 - x1;  dy1 = y2 - y1

    # the second line is ptA + s*(ptB-ptA)
    x, y = ptA;   xB, yB = ptB;
    dx = xB - x;  dy = yB - y;

    # we need to find the (typically unique) values of r and s
    # that will satisfy
    #
    # (x1, y1) + r(dx1, dy1) = (x, y) + s(dx, dy)
    #
    # which is the same as
    #
    #    [ dx1  -dx ][ r ] = [ x-x1 ]
    #    [ dy1  -dy ][ s ] = [ y-y1 ]
    #
    # whose solution is
    #
    #    [ r ] = _1_  [  -dy   dx ] [ x-x1 ]
    #    [ s ] = DET  [ -dy1  dx1 ] [ y-y1 ]
    #
    # where DET = (-dx1 * dy + dy1 * dx)
    #
    # if DET is too small, they're parallel
    #
    DET = (-dx1 * dy + dy1 * dx)

    if math.fabs(DET) < DET_TOLERANCE: return (0,0,0,0,0)

    # now, the determinant should be OK
    DETinv = 1.0/DET

    # find the scalar amount along the "self" segment
    r = DETinv * (-dy  * (x-x1) +  dx * (y-y1))

    # find the scalar amount along the input line
    s = DETinv * (-dy1 * (x-x1) + dx1 * (y-y1))

    # return the average of the two descriptions
    xi = (x1 + r*dx1 + x + s*dx)/2.0
    yi = (y1 + r*dy1 + y + s*dy)/2.0
    
    if interge == True and (is_interge(xi)==False or is_interge(yi)==False):
        return (0,0,0,0,0)
        
    xi, yi = round(xi), round(yi)    
    valid  = 1
    if xi < max(min(x1,x2), min(x, xB)) or xi > min(max(x1,x2), max(x,xB)) or \
       yi < max(min(y1,y2), min(y, yB)) or yi > min(max(y1,y2), max(y,yB)):
        return (0,0,0,0,0)
            
    return ( xi, yi, valid, r, s )

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)


n   = int(input())
seg = [list(map(int, input().split())) for _ in range(n)] 
    
cnt = 0
for x1, y1, x2, y2 in seg:
    cnt += gcd(abs(x1-x2), abs(y1-y2)) + 1

sub = 0
for i in range(n):
    d = set()
    for j in range(i+1):
        x, y, valid, _, _ = intersectSeg(seg[i][:2], seg[i][2:], seg[j][:2], seg[j][2:], interge=True)
        
        if valid == 0: continue         
            
        if (x, y) not in d:
            d.add((x, y))
            
    sub += len(d)       
                                         
print(cnt-sub)