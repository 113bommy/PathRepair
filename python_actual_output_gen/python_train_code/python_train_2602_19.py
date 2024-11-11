n=int(input())
x=list(input())

s=len(set(x))
if n-s<=25-(s):
	print(n-s)
else:
	print(-1)
