# from debug import debug

t = int(input())

for ii in range(t):
	n, x = map(int, input().split())

	graph = [[] for i in range(n)]
	for i in range(n-1):
		a, b = map(int, input().split())
		graph[a-1].append(b-1)
		graph[b-1].append(a-1)

	if len(graph[x-1]) == 1:
		print("Ayush")
	else:
		if (n-1)%2:
			print("Ayush")
		else:
			print("Ashish")