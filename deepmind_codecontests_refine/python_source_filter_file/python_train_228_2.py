target="abcdefhijklmnopqrstuvwyz"
for _ in range(int(input())):
	n,m=map(int,input().split())
	s=input()
	l=list(map(int,input().split()))
	p=[0]*n
	for i in l:
		p[i]-=1
	p[0]=m
	for i in range(1,n):
		p[i]+=(p[i-1])
	for i in range(n):
		p[i]+=1
	d=dict()
	for i in range(n):
		if s[i] not in d:
			d[s[i]]=0
		d[s[i]]+=p[i]
	for i in target:
		if i not in d:
			d[i]=0
		print(d[i],end=' ')
	print()
