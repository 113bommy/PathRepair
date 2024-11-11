N = int(input())
for _ in range(N):
	n,m = map(int,input().split(' '))
	print('m,n',m,n)
	r_z = set()
	c_z = set()
	for i in range(n):
		chase = input().split(' ')
		for j in range(m):
			if chase[j]=='1':
				r_z.add(i)
				c_z.add(j)
	res = min(n-len(r_z),m-len(c_z))
	if res%2==1:
		print('Ashish')
	else:
		print('Vivek')