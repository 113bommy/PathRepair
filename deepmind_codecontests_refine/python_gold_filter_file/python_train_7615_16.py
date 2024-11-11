for _ in range(int(input())):
    n, k = map(int, input().split())
    count = 0
    while n > 0:
        if n % k == 0:
            n = (n//k)
            count += 1
        else:
            remainder = int(n % k)
            count += remainder
            n -= remainder
        if n == 0:
            break
    print(int(count))
