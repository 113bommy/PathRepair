n = int(input())

if n % 2:
    print(0)
else:
    print((2 + 2**(n % 4) + 1) % 5)