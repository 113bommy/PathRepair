import math
n,R,r=map(int,input().split())
if 2*r>=R and n>1:
    print('NO')
    exit()
if n==1 and r<=R:
    print('YES')
    exit()
if n==1 and r>R:
    print('NO')
    exit()
if n>1 and r>=R:
    print('NO')
    exit()
c = 2*math.pi/(2*math.asin(r/(R-r)))
if c-n>-10**-6:
    print('YES')
else:
    print('NO')