t=int(input())
for i in range(t):
	p=int(input())
	k=2
	while k<=29:
		if p%(pow(2,k)-1)==0:
			print(int(p/(pow(2,k)-1)))
			break
		else:
			k+=1
	




