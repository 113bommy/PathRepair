from functools import reduce
from fractions import gcd
n,k,*a=map(int,open(0).read().split())
if max(a)<k:
    print("IMPOSSIOBLE")
elif max(a)==k:
    print("POSSIBELE")
else:
    if k%reduce(gcd,a)==0:
        print("POSSIBELE")
    else:
        print("IMPOSSIOBLE")