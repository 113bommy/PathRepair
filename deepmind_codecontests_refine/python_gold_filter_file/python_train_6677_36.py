for i in range(int(input())):
    n, a, b = map(int, input().split())
    print(min(n * a, n // 2 * b + a * ((n + 1) // 2 - n // 2)))