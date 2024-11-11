t = int(input())
for _ in range(t):
    n = int(input())
    if n % 3 == 0:
        print(n // 3, n // 3)
    elif n % 3 == 2:
        print(n // 3, n // 3 + 1)
    else:
        print(n // 3 + 1, n // 3)
