n, m, k, x, y = map(int, input().split())
mat = [[0 for i in range(m)] for j in range(n)]


def printMatrix(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("_________________")
    print('\n'.join(table))
    print("`````````````````")


if(n == 1):
    done = True
    div, mod = divmod(k, m)
    for j in range(m):
        mat[0][j] = div
        if(mod):
            mat[0][j] += 1
            mod -= 1
elif(n * m >= k):
    for i in range(n-1, -1, -1):
        for j in range(m):
            if(k):
                mat[i][j] += 1
                k -= 1
else:
    k -= (n*m)
    div, mod = divmod(k, (n-1)*m*2)
    for i in range(n):
        for j in range(m):
            if(i == 0 or i == n-1):
                mat[i][j] += div
            else:
                mat[i][j] += div*2
            mat[i][j] += 1
    for i in range(1, n):
        for j in range(m):
            if(mod):
                mat[i][j] += 1
                mod -= 1
    for i in range(n-2, -1, -1):
        for j in range(m):
            if(mod):
                mat[i][j] += 1
                mod -= 1
MAX = 0
MIN = 10000000000000000000000000
for i in range(n):
    for j in range(m):
        MAX = max(MAX, mat[i][j])
        MIN = min(MIN, mat[i][j])
print(MAX, MIN, mat[n-x][y-1])
