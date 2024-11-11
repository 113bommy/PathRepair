for z in range(int(input())):
    n, m = map(int, input().split())
    if (n * m) % 2 == 0:
        for i in range(n):
            for j in range(m):
                if (i + j) % 2 == 0:
                    print('B', end='')
                elif i == n - 1 and j < 2:
                    print('B', end='')
                else:
                    print('W', end='')
            print()
    else:
        for i in range(n):
            for j in range(m):
                if (i + j) % 2 == 0:
                    print('B', end='')

                else:
                    print('W', end='')
            print()
