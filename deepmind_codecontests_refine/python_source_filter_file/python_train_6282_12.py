
from math import gcd

n,m = map(int,input().split())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
if n<m:
    print('0/1')
else:
    if n>m:
        if (l1[0]<0 and l2[0]<0) or (l1[0]>0 and l2[0]>0):

            print('Infinity')
        else:
            print('-Infinity')
    else:
        k = gcd(l1[0],l2[0])
        if l1[0]<0 and l2[0]<0:
            l1[0] = -1*l1[0]
            l2[0] = -1*l2[0]
        elif l1[0]<0 or l2[0]<0:
            l1[0] = -1*l1[0]
            l2[0] = abs(l2[0])
        print(str(l1[0]//k)+'/'+str(l2[0]//k))


