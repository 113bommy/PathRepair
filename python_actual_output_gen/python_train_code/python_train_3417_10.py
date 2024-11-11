for _ in range(int(input())):
    n, x = map(int, input().split())
    n -= 2
    if n <= 0:
        print(1)
    else:
        print((n//x)+1)