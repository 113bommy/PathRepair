for i in range(int(input())):
    a, b = map(int, input().split())
    print(abs(b - a) // 10 + 1)