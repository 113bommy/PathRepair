n = int(input())
if n == 0:
    print(0)
else:
    print(n + 1 if (n + 1) % 2 else (n + 1) // 2)
