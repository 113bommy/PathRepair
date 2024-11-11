for _ in range(int(input())):
	n,k=map(int,input().split())
	if k>n//2:
		print('NO')
		continue
	if n%2==0:
		print(['NO','YES'][k%2==0])
	else:
		print(['YES','NO'][k%2==0])