t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    if n < k:
        if n % 3 == 0:
            print('Bob')
        else:
            print('Alice')
    elif n == k:
        print('Alice')
    elif k == 3:
        if n % 4 == 0:
            print('Bob')
        else:
            print('Alice')
    else:
        if k % 3 == 0:
            if n % (k+1) == k:
                print('Alice')
            elif (n % (k+1)) % 3 == 1:
                print('Bob')
            else:
                print('Alice')
        else:
            if n % 3 == 0:
                print('Bob')
            else:
                print('Alice')