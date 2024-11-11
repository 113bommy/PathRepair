for i in range(int(input())):
    n, s, a, b = map(int, input().split())
    print(min(n - 1, abs(a - b) + s))