l,r,x,y,k=[int(x) for x in input().split()]
def function_k(k):
	for b in range(x,y):
		if l <= k * b <=r:
			return b
if function_k(k) is not None:
	print("YES")
else:
	print("NO")