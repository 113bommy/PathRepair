for t in range(int(input())):
	a=[int(i) for i in input().split()]
	x=0
	for i in range(4):
		if a[i]%2==0:
			x+=1
	if x==4 or x==3 or x==0:
		print("Yes")
	elif x==1 and (0 not in a[:3]):
		print("Yes")
	else:
		print("No")