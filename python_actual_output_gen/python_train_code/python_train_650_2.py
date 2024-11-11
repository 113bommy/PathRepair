n, d = map(int, input().split())
s = 0
for i in range(n+1):
	x, y = map(int, input().split())
	if x**2+y**2 <= d**2:
		s = s+1
print(s)