N = int(input())
X = []
for i in range(N):
	s, p = input().split()
	X.append([s, -int(p),  i+1])
X.sort()
for i in range(N):
	print(-X[i][2])