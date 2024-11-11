def luckyYear():
    n = int(input())
    original = n
    p = -1
    f = 0
    while n > 0:
        f = n % 10
        n //= 10
        p += 1
    f += 1
    f *= 10 ** p
    print(f)
    print(f - original)


luckyYear()
