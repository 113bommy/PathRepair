corr = lambda i, j: 0 <= i < 10 and 0 <= j < 10
def can(b):
    for i in range(10):
        for j in range(10):
            for t in range(3):
                flag = 1
                for k in range(5):
                    ni = i + dx[t] * k
                    nj = j + dy[t] * k
                    if not corr(ni, nj) or b[ni][nj] != 'X':
                        flag = 0
                        break
                if flag:
                    return 1
    return 0

def solve():
    b = [list(i) for i in a]
    for i in range(10):
        for j in range(10):
            if b[i][j] == '.':
                temp = b[i][j]
                b[i][j] = 'X'
                if can(b): return 1
                b[i][j] = temp
    return 0

dx, dy = [0, 1, 1], [1, 0, 1]
a = [input() for i in range(10)]
print('YES' if solve() else 'NO')