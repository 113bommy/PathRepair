n, m, x, y = [int(x) for x in input().split()]
print('{} {}'.format(x, y))
print('1 {}'.format(y))
for i in range(1, n + 1, 2):
    for j in range(1, m + 1):
        if j == y and i in [1, x]:
            continue
        print('{} {}'.format(i, j))
    for j in range(m, 0, -1):
        if i == n:
            break
        if j == y and i in [1, x]:
            continue
        print('{} {}'.format(i + 1, j))