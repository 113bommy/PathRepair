a,b=input().split()
a=int(a)+1
while 1:
	n=str(a)
	k=""
	for i in n:
		if i=='4' or i=='7':
			k+=i
	if k==b:
		print(a)
		break
	a+=1
