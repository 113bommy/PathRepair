def f(n):
    if n%2!=0:
        return 0
    return int(2**(n/2))

print(f(int(input())))

