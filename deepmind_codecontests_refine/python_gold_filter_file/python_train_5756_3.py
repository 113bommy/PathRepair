T = int(input())
for t in range(T):
    n = int(input())
    print(2)
    if n == 2:
        print(2, 1)
    else:
        print(n, n - 2)
        print(n - 1, n - 1)
        for i in range(n - 3, 0, -1):
            print(i + 2, i)