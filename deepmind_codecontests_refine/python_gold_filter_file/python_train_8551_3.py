from math import *
a,b = [int(k) for k in input().split()]
if a == b:
    print(0)
    quit()
if a > b:
    a,b=b,a
z = b-a
if z < a:
    z *= ceil(a/z)

rz = int(sqrt(z))+1
n = 0
rn = 1
en = z
rbn = z
while(n < rz):
    n +=1
    if z%n == 0:
        rn = n
        if rn >= a:
            break
        if z//rn >= a:
            rbn = z//rn
        else:
            break
k1 = rn-a
k2 = rbn-a
if k1 < 0:
    k1 = k2
if k2 < 0:
    k2 = k1
print(min(k1,k2))