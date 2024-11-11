import sys

def solve(g, r, c):
    total = sum(sum(row) for row in g)
    if total == r*c:
        return 0
    if total == 0:
        return "MORTAL"
        
    if all(g[0]) or all(g[-1]):
        return 1
    
    if all(g[i][0] for i in range(r)) or all(g[i][-1] for i in range(r)):
        return 1
    
    if any([g[0][0],g[0][-1],g[-1][0],g[-1][-1]]):
        return 2
    
    for row in g:
        if all(row):
            return 2
    for i in range(c):
        if all(g[j][i] for j in range(r)):
            return 2
    
    if any(g[0]) or any(g[-1]):
        return 3
    if any(g[i][0] for i in range(r)) or any(g[i][-1] for i in range(r)):
        return 3
    return 4

lines = list(sys.stdin.readlines())
t = int(lines[0])

i = 1
for _ in range(t):
    r, c = map(int, lines[i].split())
    i += 1
    
    g = []
    for _ in range(r):
        row = list([c=="A" for c in lines[i]])
        i += 1
        g.append(row)
        
    print(solve(g, r, c))
