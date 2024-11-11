from math import gcd
for i in range(int(input())):
    r,b,k=map(int,input().split())
    g=gcd(r,b)
    r//=g
    b//=g
    if r>b:
        r,b=b,r
    if (k-1)*r + 1 <b:
        print("rebel")
    else:
        print("obey")