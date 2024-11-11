def secrets(n):
    count = 1
    while n % count == 0:
        count *= 3
    return n // (count + 1) + 1


print(secrets(int(input())))
