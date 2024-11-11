t = int(input())

while t > 0:
    n = int(input())

    print(n // 10 if (n + 1) % 10 else (n//10) + 1)
    t -= 1
