n = input()
n = int(n)

edges = []
for i in range(n-1):
    edges.append(input())

graph = {}
for i in range(1,n+1):
    graph[i] = []

for edge in edges:
    x = edge.split(' ')
    x = map(lambda y: int(y), x)
    x = list(x)

    graph[x[0]].append(x[1])
    graph[x[1]].append(x[0])

q = 0
for key, value in graph.items():
    if len(value) == 2:
        q = 1
        break

if q == 1:
    print("NO")

if q == 0:
    print("YES")
