from sys import stdin, stdout

n, m = map(int, stdin.readline().split())
step = [(-1, 0), (1, 0), (0, -1), (0, 1)]
ans = float('inf')
challengers = []
counting = 0
maps = []

def check(s, c):
    return n > s >= 0 and m > c >= 0 and maps[s][c] == '#'


def checkfirst():
    
    for i in range(min(len(challengers), 100)):
        visit = [[0 for j in range(m)] for i in range(n)]
        s, c = challengers[i]
        maps[s][c] = '.'
        
        if i != 0:
            visit[challengers[0][0]][challengers[0][1]] = 1
            queue = []
            queue.append(challengers[0])
        else:
            visit[challengers[1][0]][challengers[1][1]] = 1
            queue = []
            queue.append(challengers[1])            
        
        h, t = 0, 1
        
        while h != t:
            s, c = queue[h]
            h += 1
            
            for a, b in step:
                if check(s + a, c + b) and not visit[s + a][c + b]:
                    visit[s + a][c + b] = 1
                    queue.append((s + a, c + b))
                    t += 1
    
        
        for i1 in range(n):
            for j1 in range(m):
                if maps[i1][j1] == '#' and not visit[i1][j1]:
                    return 1
        
        s, c = challengers[i]
        maps[s][c] = '#'        
    else:
        return 0


for i in range(n):
    maps.append(list(stdin.readline().strip()))
    counting += maps[-1].count('#')
    
    for j in range(m):
        if maps[i][j] == '#':
            challengers.append((i, j))

if counting < 3:
    stdout.write('-1')
else:
    if checkfirst():
        stdout.write('1')
    else:
        stdout.write('2')