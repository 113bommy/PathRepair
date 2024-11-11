n=int(input())
a=list(map(int,input().split()))
M=a.index(max(a))
m=a.index(min(a))
if max(a)>=-min(a):
	r=max(a)
	for i in range(n):
		a[i]+=r
	print(n*2-2)
	for i in range(n):
		if i!=M:
			print(M+1,i+1)
	for i in range(n-1):
		print(i+1,i+2)
else:
	print(n*2-2)
	r=min(a)
	for i in range(n):
		a[i]+=r
	for i in range(n):
		if i!=m:
			print(m+1,i+1)
	for i in range(n-1):
		print(i+1,i+2)
