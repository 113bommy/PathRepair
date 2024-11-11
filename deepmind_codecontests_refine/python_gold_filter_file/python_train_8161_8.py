x,y = map(int,input().split())
s = 0
z = []
for i in range(x):
	for j in range(x):
		if j == x - 1:
			if i == j:
				print(int(y/x)+(y%x))
			else:
				print(int(y/x))
		elif i == j:
			print(int(y/x)+(y%x),end=" ")
		else:
			print(int(y/x),end=" ")
