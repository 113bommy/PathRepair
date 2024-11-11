for _ in range(int(input())):
    n, m = map(int, input().split())
    if m % 2 == 1:
        for i in range(n):
            s = input()
        print('YES')
        for i in range(m + 1):
            print(i % 2 + 1, end=' ')
        print()
    else:
        A = []
        for i in range(n):
            B = input()
            A.append(B)
        k1, k2 = -1, -1
        for i in range(n):
            for j in range(i):
                if A[i][j] == A[j][i]:
                    k1, k2 = i, j
                    break
            if k1 != -1:
                break
        if k1 == -1:
            if n == 2:
                print('NO')
            else:
                x, y, z = -1, -1, -1
                if A[0][1] == A[0][2]:
                    x = 1
                    if A[1][2] == A[0][1]:
                        y = 2
                        z = 3
                    else:
                        z = 2
                        y = 3
                elif A[1][0] == A[1][2]:
                    x = 2
                    if A[0][2] == A[1][0]:
                        y = 1
                        z = 3
                    else:
                        z = 3
                        y = 1
                else:
                    x = 3
                    if A[0][1] == A[2][0]:
                        y = 1
                        z = 2
                    else:
                        z = 2
                        y = 1
                if m % 4 == 2:
                    '''if m % 8 == 6:
                        print('YES')
                        print(y, x, end=' ')
                        for i in range(m // 4):
                            if i % 2 == 0:
                                print(z, y, x, z, end=' ')
                            else:
                                print(z, x, y, z, end=' ')
                        print(y)
                    else:
                        print('YES')
                        print(x, end=' ')
                        for i in range(m // 4):
                            if i % 2 == 0:
                                print(z, y, x, z, end=' ')
                            else:
                                print(x, y, z, x, end=' ')
                        print(y, x)'''
                    print('YES')
                    print(x, end=' ')
                    for i in range(m // 4):
                        print(y, x, end=' ')
                    print(y, z, end=' ')
                    for i in range(m // 4):
                        print(y, z, end=' ')
                    print()
                else:
                    print('YES')
                    print(y, x, end=' ')
                    for i in range(m // 4 - 1):
                        print(y, x, end=' ')
                    print(y, end=' ')
                    for i in range(m // 4):
                        print(z, y, end=' ')
                    print()



        else:
            print('YES')
            for i in range(m + 1):
                if i % 2 == 0:
                    print(k1 + 1, end=' ')
                else:
                    print(k2 + 1, end=' ')
            print()