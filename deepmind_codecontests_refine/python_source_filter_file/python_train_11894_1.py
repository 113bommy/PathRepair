for _ in range(int(input())):
    n = int(input())
    if n < 4:
        print(-1)
    else:
        for i in range(n, 0, -1):
            if i % 2 == 1:
                print(i, end = ' ')
        print(4, 2, end = ' ')
        for i in range(6, n):
            if i % 2 == 0:
                print(i, end = ' ')
        print()