n = int(input())
m=0
for _ in range(n):
	x,y = map(int,input().split())
	m = max(m,x+y)
print(m)