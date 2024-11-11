n,s = list(map(int,input().split()))
if s==0:
	print("0")
elif s==1:
	print("1")
if n==1:
	print(s)
elif s>n:
	if s%n==0:
		print(int(s/n))
	else:
		print(int(s/n)+1)
elif s<=n:
	print("1")

