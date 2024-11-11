s=int(input())
n=input()
n=list(n)
a=set(n)
if a==s:
	print("-1")
else:
	print(s-len(a))
