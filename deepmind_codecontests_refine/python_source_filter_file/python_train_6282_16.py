n,m = map(int,input().split())
p = list(map(int,input().split()))
q = list(map(int,input().split()))

import math

if n == m :
    g = math.gcd(n,m)
    if q[0] < 0 :
        print(-p[0]//g,'/',-q[0]//g,sep='')
    else:
        print(p[0] // g, '/', q[0] // g, sep='')

elif n > m :
    if (p[0] < 0 and q[0] > 0 ) or (p[0]>0 and q[0]<0) :
        print('-',end='')
    print('Infinity')

else:
    print('0/1')