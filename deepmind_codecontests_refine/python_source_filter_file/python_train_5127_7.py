for i in range(int(input())):
    n, k = map(int, input().split())
    z = 3
    if n % 2 != 0:
        while n % z == 0:
            z += 2
    print(n + k * 2 if n % 2 == 0 else n + z + (k - 1) * 2)