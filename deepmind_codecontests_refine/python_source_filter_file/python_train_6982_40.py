room=[[[0 for i in range(10)]for j in range(3)]for k in range(4)]

for i in range(int(input())):
	n=list(map(int,input().split()))
	room[n[0]-1][n[1]-1][n[2]-1]=n[3]
n=0
for i in room:
	for j in i:
		print(' '+' '.join(list(map(str,j))))
		if n==2 or n==5or n==8:
			print('####################')
		n+=1
