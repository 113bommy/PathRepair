t = int(input())

for _ in range(t):
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(input())
    topright = int(arr[0][1])
    topbtm = int(arr[1][0])
    btmup = int(arr[-2][-1])
    btmleft = int(arr[-1][-2])

    if topright == 0 and topbtm == 0:
        if btmup == 0 and btmleft == 0:
            print(2)
            print('%i %i' % (n-1,n))
            print('%i %i' % (n,n-1))
        elif btmup == 0 and btmleft == 1:
            print(1)
            print('%i %i' % (n-1,n))
        elif btmup == 1 and btmleft == 0:
            print(1)
            print('%i %i' % (n,n-1))
        else:
            print(0)
    elif topright == 1 and topbtm == 1:
        if btmup == 0 and btmleft == 0:
            print(0)
        elif btmup == 0 and btmleft == 1:
            print(1)
            print('%i %i' % (n,n-1))
        elif btmup == 1 and btmleft == 0:
            print(1)
            print('%i %i' % (n-1,n))
        else:
            print(2)
            print('%i %i' % (n-1,n))
            print('%i %i' % (n,n-1))
    elif topright == 0 and topbtm == 1:
        if btmup == 0 and btmleft == 0:
            print(1)
            print('1 2')
        elif btmup == 0 and btmleft == 1:
            print(2)
            print('1 2')
            print('%i %i' % (n,n-1))
        elif btmup == 1 and btmleft == 0:
            print(2)
            print('2 1')
            print('%i %i' % (n-1,n))
        else:
            print(1)
            print('2 1')
    elif topright == 1 and topbtm == 0:
        if btmup == 0 and btmleft == 0:
            print(1)
            print('2 1')
        elif btmup == 0 and btmleft == 1:
            print(2)
            print('2 1')
            print('%i %i' % (n,n-1))
        elif btmup == 1 and btmleft == 0:
            print(2)
            print('1 2')
            print('%i %i' % (n,n-1))
        else:
            print(1)
            print('1 2')
