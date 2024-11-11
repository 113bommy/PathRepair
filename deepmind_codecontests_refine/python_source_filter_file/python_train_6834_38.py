a = int(input())
if(a==1):
	print(4)
elif(a==0):
	print(1)
else:
	if(a <= 17*2):
		n = int(a/2) -1
		num = 8
		while(n > 0 ):
			num = num*10 + 8
			n-=1
		if(a%2==1):
			num =num*10+4
		print(num)
	else:
		print(-1)