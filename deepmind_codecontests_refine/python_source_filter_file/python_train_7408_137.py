def f(n):
    if n%2!=0:
        return 0
    return int(n**(n/2))

print(f(int(input())))

