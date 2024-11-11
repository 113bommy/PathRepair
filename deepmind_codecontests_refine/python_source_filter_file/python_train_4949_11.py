def mdc(n1,n2):
	if n2 == 0:
		return n1
	return mdc(n2,n1%n2)


a,b = map(int,input().split())
if a > b:
	print(mdc(a,b))
else:
	print("1")