from sys import stdin, stdout
t=int(stdin.readline())
for _ in range(t):
	n=int(stdin.readline())
	arr=list(map(int,stdin.readline().split()))
	di={}
	counter=0
	for i in range(n):
		if arr[i] in di:
			print('YES')
			counter=1
			break
		di[i]=1
	if counter==0:
		print('NO')
	