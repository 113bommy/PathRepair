for i in range(int(input())):
	(n,x) = map(int,input().split())
	deg_x = 0

	for j in range(n-1):
		(temp1,temp2) = map(int,input().split())
		if(temp1==x or temp2==x):
			deg_x+=1

		if(deg_x<=1 or n%2==0):
			print("Ayush")
		else:
			print("Ashish")