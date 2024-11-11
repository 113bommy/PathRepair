for _ in range(int(input())):
	n,m=map(int,input().split())
	if(n%m==0 and m<n):
		print("YES")
	else:
		print("NO")