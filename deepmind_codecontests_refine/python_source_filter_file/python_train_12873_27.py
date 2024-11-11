from math import * 
k,n,s,p = [int(x) for x in input().split()]
#print(k,n,s,p)
val = ceil(n/s)
#print(val)
pack = (k*val)/p
print(int(pack))