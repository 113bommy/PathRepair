for i in range(int(input())):
	n,m=map(int,input().split())
	if n%2==0 and m==n//2:
		print("YES")
	else:
		print("NO")	