
import math
t=int(input())
while(t>0):
    a = list(map(int,input().strip().split()))
    x, n, m = a
    if(x<20):
        if(x > m * 10):
            print('NO')
        else:
            print('YES')
        t-=1
        continue
    resid= x * math.pow(0.5, n) +  2 * 10 * (1 - math.pow(0.5, n))
    if(resid > m * 10):
        print('NO')
    else:
        print('YES')
    t-=1