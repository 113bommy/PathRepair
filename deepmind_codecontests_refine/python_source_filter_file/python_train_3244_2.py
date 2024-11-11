m= int(input())
for i in range(m):
	n= int(input())
	a=sorted(list(map(int, input().split())))
	j,k=0,0
	count=0
	for i in a:
		if i%3==0:
			count=count+1
		elif i%3==1:
			j=j+1
		else:
			k=k+1
	
	count=count+min(j,k)
	count=count+abs((j-k)//3)
	print(count)