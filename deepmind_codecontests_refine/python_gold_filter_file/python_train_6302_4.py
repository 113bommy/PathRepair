n = int(input())
if n > 90 * 2 + 9:
    z = 100
    n = n - 90 * 2 - 10
    z += n // 3
    n = n - n // 3 * 3
    z = str(z)
    print(z[n])
elif n > 9:
    z = 10
    n = n - 10
    z += n // 2
    n = n - n // 2 * 2
    z = str(z)
    print(z[n])
else:
    print(n)
