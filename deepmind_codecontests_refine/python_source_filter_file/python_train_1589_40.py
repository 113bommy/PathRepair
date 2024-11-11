for i in range(int(input())):
    x, y, n = map(int, input().split())
    while True:
        if n % x == y:
            print(n)
            break
        else:
            if n % x == n:
                print(0)
                break
            else:
                if n % x < y:
                    n -= ((n % x) + (x - y))
                else:
                    n -= ((n % x) - y)