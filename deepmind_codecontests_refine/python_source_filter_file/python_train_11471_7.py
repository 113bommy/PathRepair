for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    a.sort()

    # while i <= 4 * n:
    # current = 0
    # for i in range(4 * n - 1):
    #     if a[i+1] == a[i]:
    #         current += 1
    #     else:
    #         if current % 2 != 0:
    #             print('NO')
    #             break
    #         else:
    #             current = 1

    for i in range(0, 2*n , 2):
        if a[i] == a[i+1]:
            pass
        else:
            print('NO')
            break
    else:
        area = a[0] * a[-1]

        for i in range(n):
            if a[2*i] * a[- 2*i - 1] == area:
                pass
            else:
                print('NO')
                break
        else:
            print('YES')