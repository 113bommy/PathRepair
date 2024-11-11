n = int(input())
for i in range(n):
	x,y = (map(int,input().split()))
	m = max(0,x+y)
print(m)