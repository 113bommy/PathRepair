for x in range(int(input())):
	n,s,a,b=map(int,input().split())
	if abs(a-b)==(n-1):print(abs(a-b))
	else:
		if abs(a-b)+s>(n-1):print(abs(a-b))
		else:print(abs(a-b)+s)