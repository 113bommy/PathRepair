n= int(input())
if n%2==1:
	print("1",end=" ")
	n=n-1
	a=n//2
	if a%3==0:
		print(a-1,a+1)
	else:
		print(a,a)
if n%2==0:
	a=n//2
	y=a%3
	if y==0:
		print(a-1,a-1,2)
	if y==1:
		print(a-2,a,2)
	if y==2:
		print(a-1,a-1,2)