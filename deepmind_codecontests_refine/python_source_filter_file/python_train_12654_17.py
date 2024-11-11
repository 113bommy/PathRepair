n=int(input())
l,index1,index2,flag=[],-1,-1,True
for i in range(n):
	s=list(map(int,input().split()))
	if flag==True and 0 in s:
		index1=i
		index2=s.index(0)
		flag=False
	l.append(s)
s1,s2=0,0
if n==1 and l[0][0]==0:
	print(1)
	exit(0)
for i in range(n):
	if i==index1:
		continue
	s1=sum(l[i])
	break
for i in range(n):
	if i==index2:
		continue
	for j in range(n):
		s2+=l[j][i]
	break
if s1==s2:
	x=s1-sum(l[index1])
	if x==0:
		print(-1)
		exit(0)
	l[index1][index2]=x
	s1,s2,s3,s4,m1,m2=0,0,0,0,[],[]
	for i in range(n):
		m1.append(sum(l[i]))
	y=list(set(m1))
	if len(y)==1:
		s1=y[0]
	else:
		print(-1)
		exit(0)
	for i in range(n):
		s2=0
		for j in range(n):
			s2+=l[j][i]
		m2.append(s2)
	z=list(set(m2))
	if len(z)==1:
		s2=z[0]
	else:
		print(-1)
		exit(0)
	for i in range(n):
		s3+=l[i][i]
	j=n-1
	for i in range(n):
		s4+=l[i][j]
		j-=1
	if s1==s2==s3==s4:
		print(x)
	else:
		print(-1)
else:
	print(-1)