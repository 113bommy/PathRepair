def vector(a, b, c, d):
    return([c - a, d - b])

def cross_product(a, b):
    return(a[0] * b[1] - a[1] * b[0])

def dot_product(a, b):
    return(a[0] * b[0] + a[1] * b[1])

def bin_search(lo, hi):
    while (hi - lo > 1):
        mid = (lo + hi) // 2;
        if cross_product(vector(0, mid, mid, 0), vector(0, mid, x1, y1)) < EPS:
            hi = mid
        else:
            lo = mid
    return(hi)
            

x, y = list(map(int, input().split()));
EPS = 1e-9
x1, y1 = abs(x), abs(y);
res = int((bin_search(max(x1, y1), 1e18)));
if x < 0:
    if y < 0:
        print(-res, 0, 0 -res)
    else:
        print(-res, 0, 0, res)
else:
    if (y > 0):
        print(0, res, res, 0)
    else:
        print(0, -res, res, 0)