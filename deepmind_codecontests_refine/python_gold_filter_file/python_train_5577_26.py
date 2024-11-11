n,a,b,c = map(int,input().split())
if n % 4 == 0:
    print(0)
else:
    p = 4 - (n % 4)
    if p == 1:
        print(min([3 * c, a,b + c]))
    elif p == 2:
        print(min([2 * c, b, 2 * a]))
    else:
        print(min([c, b + a, 3*a, ]))
