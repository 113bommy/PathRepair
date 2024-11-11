t=int(input())


def computeGCD(x, y):
    if x > y:
        small = y
    else:
        small = x
    for i in range(1, small + 1):
        if ((x % i == 0) and (y % i == 0)):
            gcd = i

    return gcd
while t:
    t-=1
    ang=int(input())
    ang=2*ang
    ans=computeGCD(ang,180)
    ans=360//ans
    x = ang * ans / 360
    if (x > ans - 2):
        ans *= 2

    print(ans)