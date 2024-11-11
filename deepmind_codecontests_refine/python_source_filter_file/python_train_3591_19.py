n,m = map(int,input().split())
if(m-1 >= n-m):
	print(max(0,m-1))
else:
	print(min(n,m+1))