s = input().split()
n = int(s[0])
m = int(s[1])

graph = [[0 for x in range(n + 1)] for x in range(n + 1)]
_graph = [[] for x in range(n + 1)]
degree = [0 for x in range(n + 1)]
min = n+n+n+1

for item in range(m):
    s = input().split()
    i = int(s[0])
    j = int(s[1])
    
    _graph[i].append(j)
    _graph[j].append(i)
    
    graph[i][j] = 1
    graph[j][i] = 1
    
    degree[i] += 1
    degree[j] += 1
  
for i in range(n):
    for item in _graph[i]:
        for k in range(n):
            if graph[i][k] == 1 and graph[j][k] == 1:
                key = degree[i] + degree[item] + degree[k]
                if key < min:
                    min = key

if min == n+n+n+1:
    print(-1)
else:
    print(min - 6)
             
         

'''
for i in range(n):
    for j in range(i + 1, n):
        if graph[i][j]:
            for k in range(j + 1, n):
                if graph[i][k] == 1 and graph[j][k] == 1:
                    key = degree[i] + degree[j] + degree[k]
                    if key < min:
                        min = key

if min == n+n+n+1:
    print(-1)
else:
    print(min - 6)
'''
    
'''
15 15
4 15
12 1
15 6
11 6
15 7
6 8
15 10
6 12
12 8
15 8
15 3
11 9
7 3
6 4
12 11
'''


               
    
    
     
 