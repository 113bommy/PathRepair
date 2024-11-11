import sys
fin = sys.stdin
n = int(fin.readline())
ma = [[None]] * n
for i in range(0, n):
    aux = fin.readline()
    aux = aux[:-1]
    ma[i] = list(aux)
r = []
for i in range(0, 2 * n - 1):
    r.append(None)
    r[i] = []
    for j in range(0, 2 * n - 1):
        r[i].append('x')
for i in range(0, n):
    for j in range(0, n):
        if ma[i][j] == 'o':
            for ii in range(0, n):
                for jj in range(0, n):
                    if ma[ii][jj] == '.':
                        r[n - 1 + ii - i][n - 1 + jj - j] = '.'
g = 1
r[n - 1][n - 1] = 'o'
for i in range(0, n):
    for j in range(0, n):
        if ma[i][j] == 'x':
            cg = 0
            for ii in range(0, n):
                for jj in range(0, n):
                    if ma[ii][jj] == 'o' and r[n - 1 - ii + i][n - 1 - jj + j] == 'x':
                        cg = 1
            if cg != 1:
                g = 0
if g != 1:
    print('NO')
else:
    print('YES')
    for line in r:
        print(''.join(line))
