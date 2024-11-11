n=int(input())
if n%3==0 and n%9==0:
	print(n//3-2,n//3-2,n//3+4)
elif n%3==0 and n%9!=0:
	print(n//3,n//3,n//3)	
elif n%3==1 and (n-(n%3))%9==0:
	print(n//3+4,n//3-1,n//3-2)
elif n%3==1 and (n-(n%3))%9!=0:
	if (n-(n%3))%9==3:
		print(n//3,n//3,n//3+1)
	elif (n-(n%3))%9==6:
		print(n//3-1,n//3-1,n//3+3)
elif n%3==2 and (n-(n%3))%9==0:
	print(n//3-1,n//3-1,n//3+4)	
elif n%3==2 and (n-(n%3))%9!=0:
	if (n-(n%3))%9==3:
		print(n//3+1,n//3+1,n//3)	
	elif (n-(n%3))%9==6:
		print(n//3,n//3,n//3+2)