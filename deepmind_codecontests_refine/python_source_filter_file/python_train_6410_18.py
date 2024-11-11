import math
n, m, k, x, y = map(int, input().split())
if n < 3:
    ma, mi = math.ceil(k/(n*m)), k//(n*m)
    s = ma if k%(n*m) >= (x-1)*m+y else mi
    print(ma, mi, s)
else:
    t, mo = k//((2*n-2)*m), k%((2*n-2)*m)
    if mo > n*m:
        ma = 2*t+2
        mi = t+1
    elif mo == n*m:
        ma = 2*t+1
        mi = t+1
    elif mo > (n-1)*m:
        ma = 2*t+1
        mi = t

    elif mo > m:
        ma = 2*t+1
        mi = t
    else:
        ma = max(2*t, t+1)
        mi = t
    if x==1 or x==n:
        if mo >= (x-1)*m+y:
            s = t+1
        else:
            s = t
    else:
        if mo >= n*m+(n-x)*m+y:
            s = 2*t+2
        elif mo >= (x-1)*m+y:
            s = 2*t+1
        else:
            s = 2*t
    print(ma,mi,s)

