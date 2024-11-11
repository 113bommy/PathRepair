
n=int(input())
for q in range(n):
	s,c=input().split()
	s=list(s)
	c=list(c)
	a=sorted(s)
	t=[(i,a[i]) for i in range(len(a))]
	if s!=t:
		for i,j in t:
			if s[i]!=j:
				x=s[i]
				s[i]=j
				break
		for k in range(len(s)-1,-1,-1):
			if s[k]==j:
				s[k]=x
				break
	if s<c:
		print("".join(s))
	else:
		print('---')