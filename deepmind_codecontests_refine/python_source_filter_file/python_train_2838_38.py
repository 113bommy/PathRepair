t = int(input())
for test in range(t):
	x,y,z = [int(i) for i in input().split()]
	m = max(x,y,z)
	if (x==m) + (y==m) + (z==m) > 1:
		print("YES")
		print(m,m,min(x,y,z))
	else:
		print("NO")