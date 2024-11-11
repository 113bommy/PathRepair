# python3

WIDTH = 300
assert WIDTH >= 256


def add(n):
    if n == 1:
        add(2)
        add(255)
    elif n:
        print('.' * WIDTH)
        print('X' * (n - 1) + '.' * (WIDTH - n) + 'X')
        print('X' * WIDTH)


def print_mem2():
    print('.' * WIDTH)
    print('XX' + '.' * (WIDTH - 2))
    print('.X' + '.' * (WIDTH - 2))


# main
mem2 = 0
for symbol in map(ord, input()):
    add((symbol - mem2) % 256)
    mem2 = symbol
    print_mem2()
