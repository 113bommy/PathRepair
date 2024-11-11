k, d = map(int, input().split())
if d != 0:
    print(d*pow(10, (k-1)))
else:
    if k == 1:
        print(0)
    else:
        print('no solution')
