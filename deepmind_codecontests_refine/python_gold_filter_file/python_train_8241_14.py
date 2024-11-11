t=int(input())
for nt in range(t):
	n,m=map(int,input().split())
	num=n//10
	new = num//m
	x=int(str(m)[-1])
	if (x==1 or x==3 or x==7 or x==9):
		ans=new*45
		num2 = n-(new*m*10)
		#print (ans,new,num2)
		for i in range(1,10):
			if (m*i)<=num2:
				ans+=(int(str(m*i)[-1]))
			else:
				break
	elif (x==4 or x==8 or x==2 or x==6):
		ans=new*40
		num2 = n-(new*m*10)
		#print (ans,new,num2)
		for i in range(1,10):
			if (m*i)<=num2:
				ans+=(int(str(m*i)[-1]))
			else:
				break
	else:
		if x==0:
			ans=0
		else:
			ans=new*25
			num2 = n-(new*m*10)
			#print (ans,new,num2)
			for i in range(1,10):
				if (m*i)<=num2:
					ans+=(int(str(m*i)[-1]))
				else:
					break
	print (ans)