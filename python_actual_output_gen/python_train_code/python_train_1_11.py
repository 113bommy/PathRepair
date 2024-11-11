n=int(input())
for i in range(n):
	l,r,d=map(int,input().split())
	if d<l or d>=r:
		print(d)
	# elif d==r and d==10**9:
	# 	print(10**9)
	else:
		print(((r//d)+1)*d)