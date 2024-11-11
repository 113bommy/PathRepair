for x in range(int(input())):
	n=int(input())
	a=input()
	b=input()
	sa=0
	sb=0
	for x in range(n):
		if int(a[x])-int(b[x])>0:
			sa+=1
		elif int(b[x])-int(a[x])>0:
			sb+=1
	if sa>sb:
		print("RED")
	elif sb>sa:
		print("Blue")
	else:
		print("DRAW")