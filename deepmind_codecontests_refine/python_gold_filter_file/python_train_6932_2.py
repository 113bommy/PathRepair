import math


def gcdExtended(a, b):

    if a == 0:
        return b, 0, 1

    gcd, x1, y1 = gcdExtended(b % a, a)


    x = y1 - (b // a) * x1
    y = x1

    return gcd,x,y
a,b,c=map(int,input().split())
if a==0:
    if (c%b)==0:
        print(0, -c//b)

    else:
        print(-1)

elif b==0:
    if (c % a) == 0:
        print(-c// a, 0)

    else:
        print(-1)

elif c%(math.gcd(a,b))!=0:
    print(-1)

else:
    gcd,p,q=gcdExtended(a,b)
    print(p*(-c//gcd), q*(-c//gcd))


