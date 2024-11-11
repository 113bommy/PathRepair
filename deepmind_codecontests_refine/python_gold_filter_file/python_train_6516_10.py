n = int(input())
i = 0
while i < n:
    if i % 4 < 2:
        print('a', end='')
    else:
        print('b', end='')
    i += 1
