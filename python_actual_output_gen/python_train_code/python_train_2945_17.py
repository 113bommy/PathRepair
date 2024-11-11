for t in range(int(input())):
    x, n, m = map(int, input().split())
    while x > 21 and n:
        x = x // 2 + 10
        n -= 1
    print('NO' if x > 10 * m else 'YES')