n=int(input())
v=[int(x) for x in input().split(' ')]
sm=v[0]
for c in range(n-1):
	sm+=abs(v[c+1]-v[c])
print(sm)