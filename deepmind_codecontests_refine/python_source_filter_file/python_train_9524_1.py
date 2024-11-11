import sys
n = int(input())
s = [input() for i in range(n)]
a = [[1] * (2 * n) for i in range(2 * n)]

for i in range(n):
    for j in range(n):
        if s[i][j] != 'o':
            continue
        for x in range(n):
            for y in range(n):
                if s[x][y] == '.':
                    a[n + x - i][n + y - j] = 0
for i in range(n):
    for j in range(n):
        if s[i][j] != 'x':
            continue
        c = 0
        for x in range(n):
            for y in range(n):
                if s[x][y] == 'o' and a[n + i - x][n + j - y] == 1:
                    c = 1
                    break
            if c == 1:
                break
        if c == 0:
            print('NO')
            sys.exit(0)
print('YES')
for i in range(1, 2 * n):
    for j in range(1, 2 * n):
        if i == n and j == n:
            print('o', end=' ')
        elif a[i][j] == 1:
            print('x', end=' ')
        else:
            print('.', end=' ')
    print('')

