for _ in range(int(input())):
	d={}
	n=int(input())
	l=[]
	count=0
	for i in range(n):
		t=int(input())
		l.append(t)
		if t in d:
			d[t]+=1
		else:
			d[t]=1
	for i in d:
		count+=d[i]-1
	for i in range(n):
		j=0
		q=3
		temp=l[i]
		while l.count(l[i])>1:
			s=str(l[i])
			if j>=10:
				q=2
				s=str(temp)
			if j>=20:
				q=1
				s=str(temp)
			if j>30:
				q=0
				s=str(temp)
			t=s[:q]+str((int(s[q])+1)%10)+s[q+1:]
			j+=1
			l[i]=int(t)
	print(count)
	for i in l:
		print(i)