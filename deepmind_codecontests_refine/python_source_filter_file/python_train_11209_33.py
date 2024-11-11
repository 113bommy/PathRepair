n=int(input())
a=[int(i) for i in input().split()]
if(n==1):
	print(-1)
elif(n==2 and a[0]==a[1]):
	print(-1)
else:
	if(sum(a)==2*a[0]):
		print(1)
		print(1,2)
	else:
		print(1)
		print(1)