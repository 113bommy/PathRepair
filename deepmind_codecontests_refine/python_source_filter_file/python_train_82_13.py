from math import gcd
for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    g=gcd(b,d)
    r=a%g
    if r>=b-d and c>=b-(g-r) and a>=b:
        print("Yes")
    else:
        print("No")
