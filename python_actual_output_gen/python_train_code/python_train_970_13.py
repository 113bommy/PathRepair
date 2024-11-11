x=int(input())
i2=input().split()
if(int(i2[0])%10==7 or int(i2[1])%10==7):
	print (0)
else:
	h=int(i2[0])
	m=int(i2[1])
	count=0
	flag=0
	while True:
		while m>=6:
			flag=1
			if m%10==7 or h%10==7:
				break
			else:
				m=m-x
				count+=1
		if flag==0:
			count+=1
		if h%10==7 or m%10==7:
			break
		h=(h-1)%24
		m=m+60
	print(count)


