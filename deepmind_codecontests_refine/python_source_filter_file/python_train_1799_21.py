for _ in range(int(input())):
    x = int(input())
    i = 0
    a = 0
    n = 0
    while x >= 0:
        n += 2 ** i
        a = (1 + n) / 2 * n
        x -= a
        i += 1
    #     print(a)
    # if x < 0:
    #     i -= 1
    print(i-1)
