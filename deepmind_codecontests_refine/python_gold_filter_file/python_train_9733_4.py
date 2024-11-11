n = int(input())
xa, ya = map(int, input().split(" "))
xo, yo = map(int, input().split(" "))
xe, ye = map(int, input().split(" "))

a, o, e = xa, xo, xe
n = n - xa - xo - xe
ya, yo, ye = ya-xa, yo-xo, ye-xe

if ya > n:
    a = a+n
    n = 0
else:
    a += ya
    n = n - ya
    if yo > n:
        o = o+n
        n = 0
    else:
        o += yo
        n = n -yo
        if ye > n:
            e = e+n
            n = 0
        else:
            e += ye
            
print(a, o, e)