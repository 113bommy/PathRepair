n = int(input())
if n % 2 == 0 | n <= 4:
    print(0)
elif n % 4 == 0:
    n = n // 4 - 1
    print(n)
else:
    n = n // 4
    print(n)
