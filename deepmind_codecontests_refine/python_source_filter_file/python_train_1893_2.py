n = int(input())

edges = [[] for i in range(n)]

for i in range(n):
    s = input()
    for j in range(n):
        if s[j] == "1":
            edges[i].append(j)

m = int(input())
path = [int(i)-1 for i in input().split()]

dist = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    visited = [-1 for j in range(n)]
    visited[0] = i
    
    act = 0
    num_visited = 1
    while act < num_visited:
        for neigh in edges[visited[act]]:
            if neigh not in visited:
                dist[i][neigh] = dist[i][visited[act]]+1
                visited[num_visited] = neigh
                num_visited += 1
        act += 1

ans = [path[0]]
act = 0

for i in range(1, m-1):
    if dist[ans[-1]][path[i]] < (i-act):
        act += 1
        ans.append(path[i-1])
        
ans.append(path[-1])

print(len(ans))
print(" ".join([str(i+1) for i in ans]))