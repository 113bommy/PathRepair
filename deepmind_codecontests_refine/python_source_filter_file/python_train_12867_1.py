from sys import stdin, stdout

n, x = map(int, stdin.readline().split())
length = [[] for i in range(x + 1)]
mins = [[] for i in range(x + 1)]
challengers = []

for i in range(n):
    l, r, v = map(int, stdin.readline().split())
    
    if (r - l < x):
        length[r - l + 1].append((l, v))

for i in range(1, x + 1):
    if not len(length[i]):
        continue
    else:
        length[i].sort()
        mn = length[i][-1][-1]
        mins[i].append(mn)
        
        for j in range(len(length[i]) - 2, -1, -1):
            mn = min(mn, length[i][j][-1])
            mins[i].append(mn)
        
        mins[i] = mins[i][::-1]


INF = float('inf')
ans = INF

for i in range(1, x + 1):
    if not len(length[i]) or not len(length[x - i]):
        continue
    
    for j in range(len(length[i])):
        pos, v = length[i][j]
        
        l, r = -1, len(length[x - i])
        while (r - l > 1):
            m = (r + l) // 2
            
            if length[x - i][m][0] > pos + i:
                r = m
            else:
                l = m
                
        if r != len(length[x - i]):
            ans = min(ans, v + mins[x - i][r])


if ans == INF:
    stdout.write('-1')
else:
    stdout.write(str(ans))