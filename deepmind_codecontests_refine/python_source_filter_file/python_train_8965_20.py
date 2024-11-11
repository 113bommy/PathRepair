x = int(input())
z = []
for i in range(x):
	a = list(map(int,input().split()))
	z.append(a)
for i in range(x):
	if z[i][0] == z[i][2] and z[i][1] == z[i][3]:
		print(z[i][0],z[i][1])
	elif z[i][0] != z[i][2] and z[i][1] - z[i][0]<=1 and z[i][3] - z[i][2]<=1:
		print(z[i][0]+1,z[i][2]+1)
	elif z[i][1] != z[i][3]:
		print(z[i][1]-1,z[i][3]-1)