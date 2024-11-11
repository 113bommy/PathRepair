s= input("").split(' ')
n= int(s[0])
k= int(s[1])

if k>n:
	print(str(k))
else:
	
	a=int(n/k)
	counter= k*a
	while True:	
		
		if(counter>n):
			print(str(counter))
			break
		counter=counter+1

