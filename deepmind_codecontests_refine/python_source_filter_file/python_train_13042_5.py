res = []
 
 
def move(table, tup):
    a, b, c, d, e, f = tup
    res.append((a, b, c, d, e, f))
    table[a][b] = 1 - table[a][b]
    table[c][d] = 1 - table[c][d]
    table[e][f] = 1 - table[e][f]
 
def solve22(n1, m1, n, m, table):
    cur = [table[n1][m1], table[n1][m1 + 1], table[n1 + 1][m1], table[n1 + 1][m1 + 1]]
    if cur == [0, 0, 0, 0]:
        return
    cnt1 = 0
    for c in cur:
        if c == 1:
            cnt1 += 1
    l = []
    if cnt1 == 3:
        for n2 in range(n1, n):
            for m2 in range(m1, m):
                if table[n2][m2] == 1:
                    l += [n2, m2]
        move(table, tuple(l))
    else:
        for n2 in range(n1, n):
            for m2 in range(m1, m):
                if table[n2][m2] == 1:
                    l += [n2, m2]
                    if n2 - 1 >= n1:
                        l += [n2 - 1, m2]
                    if n2 + 1 < n:
                        l += [n2 + 1, m2]
                    if m2 - 1 >= m1:
                        l += [n2, m2 - 1]
                    if m2 + 1 < m:
                        l += [n2, m2 + 1]
                    move(table, tuple(l))
                    solve22(n1, m1, n, m, table)
                    return
    
 
def solve2m(n1, m1, n, m, table):
    if m - m1 == 2:
        solve22(n1, m1, n, m, table)
        return
    if table[n1][m1] == 1 and table[n1 + 1][m1] == 1:
        t = (n1, m1, n1 + 1, m1, n1, m1 + 1)
        move(table, t)
    elif table[n1][m1] == 1 and table[n1 + 1][m1] == 0:
        t = (n1, m1, n1 + 1, m1 + 1, n1, m1 + 1)
        move(table, t)
    elif table[n1][m1] == 0 and table[n1 + 1][m1] == 1:
        t = (n1 + 1, m1, n1 + 1, m1 + 1, n1, m1 + 1)
        move(table, t)
    solve2m(n1, m1 + 1, n, m, table)
    
 
def solve(n1, m1, n, m, table):
    if n - n1 == 2:
        solve2m(n1, m1, n, m, table)
        return
    for j in range(0, m - 1):
        if table[n1][j] == 1:
            t = (n1, j, n1 + 1, j, n1 + 1, j + 1)
            move(table, t)
    if table[n1][m - 1] == 1:
        t = (n1, m - 1, n1 + 1, m - 1, n1 + 1, m - 2)
        move(table, t)
    solve(n1 + 1, m1, n, m, table)
 
t = int(input())
for tt in range(t):
    n, m = map(int, input().split())
    table = []
    res = []
    for i in range(n):
        row = input()
        table.append(row)
    table = [[ord(c) - ord('0') for c in row] for row in table]
    solve(0, 0, n, m, table)
    print(len(res))
    for a, b, c, d, e, f in res:
        print(a + 1, b + 1, c + 1, d + 1, e + 1, f + 2)