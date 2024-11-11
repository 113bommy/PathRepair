for _ in range(int(input())):
    n = int(input())
    k = 3
    while n % k != 0:
        k <<= 1
        k |= 1
    print(n / k)