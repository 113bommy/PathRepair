x=int(input())
count=0

n=1
while True:
	n+=1
	ans=True
	for i in range(2,int(x**0.5)):
		if n%i==0:
			ans=False
			break
	if ans and n>=x:
		print(n)
		break
