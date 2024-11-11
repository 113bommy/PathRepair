import math
x=[int(i) for i in input().split()]
n,R,r=x[0],x[1],x[2]


if r>R:
    print('NO')
    raise SystemExit
 
if 2*r>R:
    if n>1:
        print('NO')
        raise SystemExit
    else:
        print('YES')
        raise SystemExit
z=2*n*math.asin(r/(R-r))
if z>2*math.pi+0.000001:
    print('NO')
else:
    print('YES')