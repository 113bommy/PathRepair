n,m = map(int,input().split())
rob = []
spot = []
for i in range(n):
	rob.append(list(map(int,input().split())))
for i in range(m):
	spot.append(list(map(int,input().split())))
d = {}
for i in range(n):
	for j in range(m):
		x, y = rob[i], spot[j]
		if x[0]<=y[0]:
			if y[0]-x[0] in d:
				d[y[0]-x[0]] = max(d[y[0]-x[0]], y[1]-x[1]+1)
			else:
				d[y[0]-x[0]] = y[1]-x[1]+1

# print (d)
x = [0]*(10**6+2)
for i in range(len(x)-2, -1, -1):
	if i in d:
		x[i] = max(x[i+1], d[i])
	else:
		x[i] = x[i+1]
ans = 10**6+1
for i in range(len(x)):
	ans = min(ans, i + x[i])

# print (x)
print (ans)