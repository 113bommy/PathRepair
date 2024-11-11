t,s,x=map(int,input().split())
if x>=t:
	if x==t:
		print('Yes')
	elif x==t+1 and s==1:
		print('Yes')
	elif (x-t)%s==0 or (x-t-1)%s==0:
		print('Yes')
	else:
		print('No')
else:
	print('No')
