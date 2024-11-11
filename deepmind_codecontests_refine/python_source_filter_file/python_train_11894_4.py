for k in range(int(input())):
	x=int(input())
	if x<4:
		print(-1)
		continue
	for n in range(x,0,-1):
		if n%2==1:
			print(n,end=' ')
	print(2,4,end=' ')
	for n in range(6,x+1,2):
		print(n,end=' ')
	print()
