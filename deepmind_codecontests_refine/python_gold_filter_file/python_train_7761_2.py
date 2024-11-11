class Cell:
    def  __init__(self, row, clm):
        self.row = row
        self.clm = clm

dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]

Berland = [] 
visited = [[False] * 51 for i in range(51)]
Lakes = []

def DFS(s):
    stack = [s]
    visited[s.row][s.clm] = True
    
    Ocean = False
    lake = []

    while len(stack):
        u = stack.pop()
        lake.append(u)

        if u.row == 0 or u.row == n - 1 or u.clm == 0 or u.clm == m - 1:
            Ocean = True

        for i in range(4):
            v = Cell(u.row + dr[i], u.clm + dc[i])

            if v.row >= 0 and v.row < n and v.clm >= 0 and v.clm < m and Berland[v.row][v.clm] == "." and not visited[v.row][v.clm]:
                    visited[v.row][v.clm] = True
                    stack.append(v)

    if not Ocean:
        Lakes.append(lake)

n, m, k = map(int, input().split())
for i in range(n):
    Berland.append(list(input()))

for i in range(n):
    for j in range(m):
        if not visited[i][j] and Berland[i][j] == ".":
            DFS(Cell(i, j))

Lakes.sort(key = lambda lake: len(lake))
change = len(Lakes) - k
cells_change = 0
for i in range(change):
    cells_change += len(Lakes[i])
    for s in Lakes[i]:
        Berland[s.row][s.clm] = "*"

print(cells_change)
for i in range(n):
    print(*Berland[i], sep = "")