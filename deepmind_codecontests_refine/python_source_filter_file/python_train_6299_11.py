from queue import Queue
 
n, m = map(int, input().split())
 
roads = [[1 for i in range(n)] for j in range(n)]
dist = [0 for i in range(n)]
 
for i in range(m):
	x, y = map(int, input().split())
	x -= 1
	y -= 1
	roads[x][y] = 2
	roads[y][x] = 2
 
value = roads[0][n - 1]
dist[0] = 0
 
aux = Queue()
aux.put(0)
 
while not aux.empty():
	top = aux.get()
 
	for i in range(len(roads[0])):
		edge = roads[top][i]
		if (edge != value) and ((dist[top] + 1) < dist[i]): 
			aux.put(i)
			dist[i] = dist[top] + 1
 
if dist[n - 1] != 0:
  print(dist[n - 1]) 
else:
  print('-1')













