n, x = [int(i) for i in input().split()]
a = 0
if (n - 1) % 2 == 0:
    for i in range(10 ** 6, 10 ** 6 - n + 1, -1):
        a = a ^ i
    for i in range(10 ** 6 - n):
        if a ^ i == x:
            print("YES")
            for j in range(10 ** 6, 10 ** 6 - n + 1, -1):
                print(j, end=" ")
            print(i)
            exit()
    print("NO")
else:
    if n == 2 and x == 0:
        print("NO")
        exit()
    if n == 2:
        print("YES")
        if x != 0:
            print(0, x)
        exit()
    for i in range(10 ** 6, 10 ** 6 - n + 3, -1):
        a = a ^ i
    tm = 10 ** 6 - n + 3
    if x == a ^ tm:
        a = a ^ (tm - 1) ^ 1
        for i in range(10 ** 6 - n):
            if i != 1:
                if a ^ i == x:
                    print("YES")
                    for j in range(10 ** 6, 10 ** 6 - n + 3, -1):
                        print(j, end=" ")
                    print(1, end="")
                    print(tm - 1, end="")
                    print(i)
                    exit()
    a = a ^ tm
    a = a ^ 1
    for i in range(10 ** 6 - n):
        if i != 1:
            if a ^ i == x:
                print("YES")
                for j in range(10 ** 6, 10 ** 6 - n + 2, -1):
                    print(j, end=" ")
                print(1, end="")
                print(i)
                exit()
    print("NO")