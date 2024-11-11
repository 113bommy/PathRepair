n=int(input())
x=list(input())

s=len(set(x))
if n-s<=26-(s):
	print(n-s)
else:
	print(-1)
