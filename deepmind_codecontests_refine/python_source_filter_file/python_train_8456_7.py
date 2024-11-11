t=int(input())

while t>0:
	n=int(input())

	k=1
	flag= True

	while flag:
		if n%(pow(2,k)-1)==0:
			print(n/(pow(2,k)-1))
			flag=False
		else:
			k+=1
	
	t-=1
