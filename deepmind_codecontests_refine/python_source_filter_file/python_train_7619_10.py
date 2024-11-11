n, m = map(int, input().split())

g = [[]] * (n)

for a in range(n):
    g[a] = input().split()
    g[a] = [int(x) for x in g[a]]

#if that index == 0
#look down and look right
#see which one bigger
#then you -1 from there

total = 0
for c in range(n-1,0-1,-1):
    for d in range(m-1,0-1,-1):
        if g[c][d] == 0:
            g[c][d] = min(g[c+1][d],g[c][d+1])-1
        total += g[c][d]




for a in range(1,n-1):
    for b in range(1,m):
        if g[a][b] >= g[a+1][b]:
            total = -1

for a in range(1,n):
    for b in range(1,m-1):
        if g[a][b] >= g[a][b+1]:
            total = -1

print(total)
