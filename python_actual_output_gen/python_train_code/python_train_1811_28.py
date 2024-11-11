for i in range(int(input())):
	a,b=[int(j) for j in input().split()]
	a,b=min(a,b),max(a,b)
	if b<a*2 :
		print(a,a*2)
	else:
		print(-1,-1)
