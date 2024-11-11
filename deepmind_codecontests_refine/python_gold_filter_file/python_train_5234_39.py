for i in range(int(input())):
    a, b = map(int, input().split())
    if a % b == 0:
        print(0)
    else:
        c = a // b
        print((c + 1) * b - a)