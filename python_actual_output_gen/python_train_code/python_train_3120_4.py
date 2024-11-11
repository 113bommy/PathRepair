n, x = map(int,input().split())
l = list(map(int,input().split()))

z = sum(l)

if z == 0:
    print(0)
else:
    if abs(z) <= n:
        print(1)
    else:
        if abs(z) % n == 0:
            print(abs(z) // n)
        else:
            print(abs(z) // n + 1)