n, m = map(int, input().split())
ss = [input() for i in range(n)]
s = [[1 if x == '*' else 0 for x in y] for y in ss]

dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

ok = True
for i in range(1, n-1):
    if not ok:
        break
    for j in range(1, m - 1):
        k = 0
        for q in range(5):
            if s[i + dx[q]][j + dy[q]] == 1:
                k += 1
        if k !=5 :
            continue
        s[i][j] = 0
        for q in range(1, 5):
            ii = i
            jj = j
            while True:
                ii += dx[q]
                jj += dy[q]
                if not (0 <=ii < n) or not (0 <= jj < m):
                    break
                if s[ii][jj] == 1:
                    s[ii][jj] = 0
                else:
                    break
        ok = False
        break
    
any = False
for x in s:
    for y in x:
        if y == 1:
            any = True
print('NO' if any else 'YES')