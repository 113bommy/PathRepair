n = int(input())
u = [list(map(int, input().split())) for i in range(n)]
z = [u[i][0] + u[i][1] for i in range(n)]
w = [u[i][0] - u[i][1] for i in range(n)]
d = [max(z)-min(z), max(w)-min(w)]

print(max(d))
	
