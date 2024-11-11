def print_to_right(n, characters):
    for i in range(n):
        print(f'PRINT {characters[i]}')

        if i != n - 1:
            print('RIGHT')


def print_to_left(n, characters):
    for i in range(n - 1, -1, -1):
        print(f'PRINT {characters[i]}')

        if i != 0:
            print('LEFT')


n, k = map(int, input().split())
characters = input()

if k == 1:
    print_to_right(n, characters)
elif k == n:
    print_to_left(n, characters)
else:
    if k > n // 2:
        for i in range(n - k):
            print('RIGHT')

        print_to_left(n, characters)
    else:
        for i in range(0, k):
            print('LEFT')

        print_to_right(n, characters)
