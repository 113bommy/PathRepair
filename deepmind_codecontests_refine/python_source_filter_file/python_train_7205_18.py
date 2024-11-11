for i in range(int(input())):
	*a,n=map(int,input().split())
	a.sort()
	n -= 2*a[2]-a[0]-a[1]
	if n%3==0 and n>0:
		print("YES")
	else:
		print("NO") 