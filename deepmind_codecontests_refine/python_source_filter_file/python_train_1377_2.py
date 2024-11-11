for _ in range(int(input())):
	a=input()
	b=input()
	c=input()
	f="YES"
	for i in range(len(a)):
		if a[i]!=c[i] and b[i]!=c[i]:
			f="NO"
print(f)