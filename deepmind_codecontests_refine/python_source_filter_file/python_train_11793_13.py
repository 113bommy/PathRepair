from math import acos, pi
[n,R,r] = list(map(float,input().split())) 
eps = 1e-7
if R < r:
    print('NO')
else:
    if R == r:
        if n == 1:
            print('YES')
        else:
            print('NO')
    elif R < 2*r:
        if n > 1:
            print('NO')
        else:
            print('YES')
    else:
        a = acos(1 - 2*r**2/(R-r)**2)
        if a-eps <= 2*pi/n:
            print('YES')
        else:
            print('NO')