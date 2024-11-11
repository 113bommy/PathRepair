import sys
sys.setrecursionlimit(1000000000)

def bfs(x, y):
    q = [(y, x)]
    
    while q:
        x = q[0][1]
        y = q[0][0]
        q.pop(0)
        if (x-1 > -1) and (g[y][x-1] == '.'):
            g[y][x-1] = 'X'
            q.append((y, x-1))
        if (x+1 < m) and (g[y][x+1] == '.'):
            g[y][x+1] = 'X'
            q.append((y, x+1))
        if (y-1 > -1) and (g[y-1][x] == '.'):
            g[y-1][x] = 'X'
            q.append((y-1, x))
        if (y+1 < n) and (g[y+1][x] == '.'):
            g[y+1][x] = 'X'
            q.append((y+1, x))
            
            
n, m = map(int, input().split())
g = [['']*m for i in range(n)]
for i in range(n):
    t = input()
    for j in range(m):
        g[i][j] = t[j]

y, x = map(int, input().split())
b, a = map(int, input().split())
x -= 1
y -= 1
a -= 1
b -= 1
    
if (x == a) and (y == b):  # если начало и конец пути совпадают
    if ((x-1 > -1) and (g[y][x-1] == '.')) or ((x+1 < m) and (g[y][x+1] == '.')) or ((y-1 > -1) and (g[y-1][x] == '.')) or ((y+1 < n) and (g[y+1][x] == '.')):
        print('YES')
    else:
        print('NO')
        
else:  # если финишная клетка треснувшая или у нее есть целые соседи
    f = False
    if g[b][a] == '.':
        f = True
        
    one = (a-1 > -1) and (g[b][a-1] == '.')
    two = (a+1 < m) and (g[b][a+1] == '.')
    three = (b-1 > -1) and (g[b-1][a] == '.')
    four = (b+1 < n) and (g[b+1][a] == '.')

    g[b][a] = '.'
    bfs(x, y)
    
    if g[b][a] == 'X':
        if f:
            if one+two+three+four > 1:
                print('YES')
            elif (((a == x-1) and (b == y)) or ((a == x+1) and (b == y)) or ((a == x) and (b == y-1)) or ((a == x) and (b == y+1))) and (one+two+three+four == 1):
                print('YES')
            else:
                print('NO')
        else:
            print('YES')
    else:
        print('NO')