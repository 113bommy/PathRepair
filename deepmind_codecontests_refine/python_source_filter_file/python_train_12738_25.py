x=int(input())
if x%2==0:
	for i in range(x):
		if i%2==0:
			print(i+2,end='')
		else:
			print(i,end='')

else:
	print(-1)