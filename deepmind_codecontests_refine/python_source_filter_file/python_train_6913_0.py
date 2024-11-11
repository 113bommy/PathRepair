d,r = map(int,input().split())
if r == 0:
    if d == 1:
        print(0)
    else:
        print('no solution')
else:
    print((10**(d-1))*r)