n=int(input())
k=['vaporeon']
six=['espeon']
sev=['jolteon','flareon','umbreon','leafeon','glaceon','sylveon']
s=input().strip()
if n==6:print(*six)
elif n==8:print(*k)
else:
	p=False
	z=[]
	for x in range(n):
		if s[x]!='.':
			z.append((s[x],x))
	for x in sev:
		for m,n in z:
			if x[n]!=m:
				break
		else:
			print(x)
			p=True
		if p==True:break