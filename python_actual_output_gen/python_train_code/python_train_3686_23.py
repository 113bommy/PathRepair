for _ in range(int(input())):
	r,g,b= list(map(int,input().split()))
	l=[r,g,b]
	l.sort()
	print(l)
	r,g,b=l
	if 1+ r+g>=b:
		print("Yes")
	else:
		print("No")