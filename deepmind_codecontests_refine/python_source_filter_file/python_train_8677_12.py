'''
import math
n=int(input())
a=[int(x) for x in input().split()]
for x in a:
    if  x==1 or (not int(math.sqrt(x))==math.sqrt(x)):
        print('NO')
        continue
    if x==4:
        print('YES')
        continue
    sgn=1
    for i in range(2,int(math.sqrt(x))):
        if x//i!=x/i:
            continue
        else:
            print('NO')
            sgn=0
            break
    if sgn==1:
        print('YES')
'''
from math import sqrt
def e(n,pr):
    p=2
    while p*p<=n:
        if (pr[p]==True):
            for i in range(2*p,n+1,p):
                pr[i]=False
        p+=1
n=int(input())
pr=[True]*(10**6+1)
e(n,pr)
x=[int(x) for x in input().split()]
for i in x:
    if i<4:
        print('NO')
        continue
    elif int(sqrt(i))!=i:
        print('NO')
        continue
    if pr[int(sqrt(i))]:
        print('YES')
    else:
        print('NO')
