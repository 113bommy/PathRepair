m,n=map(int,input().split())
z=min(m,n)
i=0
while(m>=0 or n>=0):
	if i%2==1:
		m=m-i
		if m<0:
			print("Vladik")
			break
	elif i%2==0:
		n=n-i
		if n<0:
			print("Valera")
			break
	i+=1
