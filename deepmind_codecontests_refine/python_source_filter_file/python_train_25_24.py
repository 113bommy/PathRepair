ncases = int(input())

for tcase in range(ncases):
    n = int(input())
    arr = [input() for i in range(n)]
    
    n1 = arr[0][1]
    n2 = arr[1][0]
    n3 = arr[n-2][n-1]
    n4 = arr[n-1][n-1]

    if n1 == n2 and n3 == n4:
        if not n1 == n3:
            print(0)
        else:
            print(2)
            print('1 2')
            print('2 1')
    elif not n1 == n2 and n3 == n4:
        if n1 == n3: # flip n1
            print(1)
            print('1 2')
        else: # flip n2
            print(1)
            print('2 1')
    elif n1 == n2 and not n3 == n4:
        if n1 == n3: # flip n3
            print(1)
            print(n-1, n)
        else: # flip n4:
            print(1)
            print(n, n-1)
    else:
        if n1 == n3: # flip n1 n4
            print(2)
            print('1 2')
            print(n, n-1)
        else:
            print(2)
            print('2 1')
            print(n, n-1)
    