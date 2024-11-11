s=int(input())
n=input()
n=list(n)
a=set(n)
if a==s or s>26:
	print("-1")
else:
	print(s-len(a))
