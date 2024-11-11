p,q=[int(x) for x in input().split()]
parr=[int(x) for x in input().split()]
qarr=[int(x) for x in input().split()]
from math import gcd
if p==q:
    a=gcd(parr[0],qarr[0])
    sign=parr[0]*qarr[0]
    if sign>0:
        print("{}/{}".format(abs(parr[0]//a),abs(qarr[0]//a)))
    else:
        print("-{}/{}".format(abs(parr[0]//a),abs(qarr[0]//a)))

elif p>q:
    sign=parr[0]*qarr[0]
    if sign>0:
        print("Infinity")
    else:
        print("-Infinity")
elif p<q:
    print("0/1")
