n,s = map(int,input().split())
if 2*n>s:
	print("NO")
else:
	print("YES")
	for i in range(n-1):
		print(n)
	print(s-n+1)
	print(s//2)