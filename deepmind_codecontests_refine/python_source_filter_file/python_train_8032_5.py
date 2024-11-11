n, m = map(int, input().split())
p = []
for i in range(n):
    p.append(input())

ci = None
cj = None
for i in range(n):
    if i == 0 or i == n - 1:
        continue
    if ci:
        break
    for j in range(m):
        if j == 0 or j == m - 1:
            continue
        if p[i][j] == '*' and p[i - 1][j] == '*' and p[i + 1][j] == '*' and p[i][j - 1] == '*' and p[i][j + 1] == '*':
            ci = i
            cj = j
            break

if not ci:
    print('NO')
else:
    flag = True
    for i in range(n):
        if not flag:
            break
        if i == ci:
            continue
        for j in range(m):
            if not flag:
                break
            if j == cj:
                continue
            if p[i][j] == '*':
                flag = False
    if not flag:
        print('NO')
    else:
        notx = False
        j = 0
        k = m - 1
        while p[ci][j] != '*':
            j += 1
        while p[ci][k] != '*':
            k -= 1
        for i in range(j, k + 1):
            if p[ci][k] == '.':
                notx = True
        if notx:
            print('NO')
        else:
            noty = False
            x = 0
            y = n - 1
            while p[x][cj] != '*':
                x += 1
            while p[y][cj] != '*':
                y -= 1
            for i in range(x, y + 1):
                if p[i][cj] == '.':
                    noty = True
            if noty:
                print('NO')
            else:
                print('YES')




