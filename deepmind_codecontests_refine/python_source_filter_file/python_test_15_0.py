#!/usr/bin/env pypy3
from sys import stdin

lines = [line.strip() for line in stdin]
t = int(lines[0][0])
ln = 1
for _ in range(t):
    n, m, k = map(int, lines[ln].split())
    ln += 1
    g = [[1 if c == "*" else 0 for c in lines[ln+i]] for i in range(n) ]
    
    ln += n

    ng = [[0]*m for i in range(n)]

    for i in range(n):
        for j in range(m):
            for d in range(k, 20):
                if not (i - d >= 0 and j - d >= 0 and j+d < m): break
                
                if all((g[i-h][j-h] and g[i-h][j+h]) for h in range(d+1)):
                    for h in range(d+1):
                        ng[i-h][j-h] = 1
                        ng[i-h][j+h] = 1

    print("YES" if g == ng else "NO")

