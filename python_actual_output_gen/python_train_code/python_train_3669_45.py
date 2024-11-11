n,k,t=[int(x) for x in input().split()]
if t<=k:
	print(t)
elif t>k and t<=n:
	print(k)
else:
	print(t-k)