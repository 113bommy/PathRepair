import sys
v,e = input().split()
v = int(v)
e = int(e)
adj = {}
color= [int(x) for x in input().split()]

for c in color:
	adj[c] = set()
color.insert(0,0)
for i in range(e):
	a,b = input().split()
	a = int(a)
	b = int(b)
	
	if color[a] != color[b]:
		adj[color[a]].add(color[b])
		adj[color[b]].add(color[a])
min_color = sys.maxsize
max_div = 0 
for key in adj.keys():
	if len(adj[key]) > max_div:
		min_color = key
		max_div = len(adj[key])
	elif len(adj[key]) == max_div:
		if key < min_color:
			min_color = key
print(min_color)
print(adj)
