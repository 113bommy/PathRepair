dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

def isOK(x, y, field):
    for i in range(4):
        if (field[x + dx[i]][y + dy[i]] == 'L'):
            return False
    return True

n, k = map(int, input().split())

field = [['S' for i in range(n + 2)] for j in range(n + 2)]
cnt = 0

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if (isOK(i, j, field) and cnt < k):
            field[i][j] = 'L'
            cnt += 1

if (cnt == k):
    print("YES")
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(field[i][j], end = ' ')
        print()
else:
    print("NO")