def nok(n):
    if n < 3:
        return n
    if not n % 2 and n % 3:
        m = n * (n - 1) * (n - 2)
    else:
        m = 0
    n -= (n % 2 == 0)
    return max(n * (n - 1) * (n - 2), m)


print(nok(int(input())))
