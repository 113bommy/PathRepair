for x in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	a=[]
	for x in l:
		if x not in a:
			a.append(x)
	print(*a)