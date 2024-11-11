n, m = list(map(int,input().split()))
if m - n >= 5:
    print(0)
    exit()
else:
    if m - n == 1:
        print(m%10)
    elif (m-n) == 2:
        print(m*(m-1)%10)
    elif m-n == 3:
        print(m*(m-1)*(m-2)%10)
    elif m - n == 4:
        print(m*(m-1)*(m-2)*(m-3))
    elif m - n == 0:
        print(1)