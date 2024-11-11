f = []
for i in range(8):
    f.append(input())

d = [[[0 for i in range(8)] for j in range(8)] for k in range(100)]

d[0][7][0] = 1
dx = [1, 1, 1, 0, 0, -1, -1, -1]
dy = [1, 0, -1, 1, -1, 1, 0, -1]

ans = 'LOSE'
for i in range(99):
    for x in range(8):
        for y in range(8):
            if not d[i][x][y]:
                continue
            for j in range(8):
                nx = x + dx[j]
                ny = y + dy[j]
                if not(0 <= nx < 8 and 0 <= ny < 8):
                    continue

                valid = True
                if 0 <= nx - i < 8 and f[nx - i][ny] == 'S':
                    valid = False
                if 0 <= nx - i - 1 < 8 and f[nx - i - 1][ny] == 'S':
                    valid = False
                
                if not valid:
                    continue
                d[i + 1][nx][ny] = 1
                if nx == 0 and ny == 7:
                    ans = 'WIN'
print(ans)
