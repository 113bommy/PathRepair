n, x = map(int,input().split())
l = list(map(int,input().split()))

z = sum(l)

if z == 0:
    print(0)
else:
    if abs(z) <= x:
        print(1)
    else:
        if abs(z) % x == 0:
            print(abs(z) // x)
        else:
            print(abs(z) // x + 1)