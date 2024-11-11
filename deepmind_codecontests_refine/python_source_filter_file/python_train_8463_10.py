(n, m) = [int(x) for x in input().split()]
paper = []
position = []
s = 0
t = max(n,m)
u = 0
v = max(n,m)
result = []
for i in range(n):
    paper.append(list(input()))
for k in range(n):
    for j in range(m):
        if paper[k][j] == '*':
            position.append((k,j))
for w in range(len(position)):
    s = max(s,position[w][0])
    t = min(t,position[w][0])
    u = max(u,position[w][1])
    v = min(v,position[w][1])
for y in range(s-t+1):
    for r in range(u-v+1):
        result.append(paper[t+y][v+r])
for g in range(s-t+1):
##    for results in result[g*(u-v+1):(g+1)*(u-v+1)]:
##        print(results,end = '')
    results = ' '.join(result[g*(u-v+1):(g+1)*(u-v+1)])
    print(results)
