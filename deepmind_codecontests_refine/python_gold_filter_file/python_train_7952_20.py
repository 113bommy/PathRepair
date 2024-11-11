f=lambda: map(int, input().split(' '))
n, m =f()
print(n-1)
if(m==0):
	
	for j in range(2,n+1):

		print(1,' ', j)

else:
	s=set()
	for j in range(m):
		s=set(f()).union(s)

	#print(s)
	ss = set([i for i in range(1, n+1)]).difference(s)
	#print(ss)
	kp = list(ss)[0]

	for j in range(1, n+1):
		if(j!=kp):
			print(j, ' ', kp)



