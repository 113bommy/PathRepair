for _ in range(int(input())):
    a, b, c, d, k = map(int, input().split())
    x = a // c + a % c != 0
    y = b // d + b % d != 0
    if x + y > k:
        print(-1)
    else:
        print(x, y)
