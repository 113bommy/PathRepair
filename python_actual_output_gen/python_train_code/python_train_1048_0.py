import sys

def get_min_cost(n, p):
	m = [[0 for x in range(n+1)] for x in range(n+1)]
	for s in range(n):
		i = 1
		for j in range(s+2, n):
			m[i][j] = sys.maxsize
			for k in range(i, j+1):
				m[i][j] = min(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j])
			i+=1	
	return m[1][n]

n = int(input())
p = [0] * (n+1)
j = 0
for i in range(n):
	a = list(map(int, input().split()))
	if i == 0:
		p[j] = a[0]
		j += 1
	p[j] = a[1]
	j += 1
print(get_min_cost(n, p))
		
		
