def sol():
    n = int(input())

    if n == 1:
        print('x')
    elif n % 2:
        print('x'*(n // 2) + 'yz' + 'x'*(n // 2 - 1))
    else:
        print('x'*(n // 2) + 'y' + 'x'*(n // 2 - 1))

t = int(input())

for i in range(t):
    sol()