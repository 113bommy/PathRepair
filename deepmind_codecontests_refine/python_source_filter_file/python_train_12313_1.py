a,x,y=map(int,input().split())
if ((x>=a)or(x<=-a)or(y==y//a*a)or(y<0)):
	print(-1)
	exit(0)
elif ((x==0)and(y//a%2==0)and(y//a!=0)):
	print(-1)
	exit(0)
elif ((x>=(a+1)//2 or x<=-(a+1)//2)and(y//a%2==1 or y//a==0)):
	print(-1)
	exit(0)
z=y//a
#print(z)
if (z==0):
	print(1)
elif ((z-1)%2==0):
	print((z-1)//2*3+2)
else:
	if (x<0):
		print((z-1)//2*3+3)
	else:
		print((z-1)//2*3+4)