n, a = map(int, input().split())

if a % 2:
    print(int(a // 2 + 1))
else:
    print(int(n / 2 - a / 2 + 1))
