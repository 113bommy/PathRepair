# with open("input.txt",'r') as f:	
# import math
t = int(input())
while t>0:
	n  = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	if(a[0]!=b[0]):
		print("NO")
		t-=1
		continue
	indexOfOne = 1000000001
	indexOfMinusOne = 1000000001
	flag = True
	if(a[0]==1):
		indexOfOne=0
	elif(a[0]==-1):
		indexOfMinusOne=0
	for i in range(1,n):
		if(a[i]==1):
			indexOfOne = min(i,indexOfOne)
		if(a[i]==-1):
			indexOfMinusOne = min(i,indexOfMinusOne)
		if(b[i]>0):
			if(i<=indexOfOne):
				flag = False
				print("NO")
				break
		elif(b[i]<0):
			if(i<=indexOfMinusOne):
				flag=False
				print("NO")
				break
	if flag:
		# print(indexOfMinusOne,indexOfOne)
		print("YES")

	t-=1
