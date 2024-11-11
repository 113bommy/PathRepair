n,m = input().split()
n = int(n)
m = int(m)
n1 = n
m1 = m
l1 = [0]
n-=1
p1 = 0
p2 = 0
q1 = 0
q2 = 0
for i in range(1,n+m+1):
	if(i%2 == 0):
		if(l1[i-1] == 0):
			if(n>0):
				l1.append(0)
				n-=1
			else:
				l1.append(1)
				m-=1
		else:
			if(m>0):
				l1.append(1)
				m-=1
			else:
				l1.append(0)
				n-=1
	else:
		if(l1[i-1] == 0):
			if(m>0):
				l1.append(1)
				m-=1
			else:
				l1.append(0)
				n-=1
		else:
			if(n>0):
				l1.append(0)
				n-=1
			else:
				l1.append(1)
				m-=1
i=0
n = n1
m = m1
for i in range(1,n+m):
	if(l1[i] == l1[i-1]):
		p1+=1
	else:
		p2+=1
l2 = [1]
m-=1
for i in range(1,n+m+1):
	if(i%2 == 1	):
		if(l2[i-1] == 0):
			if(n>0):
				l2.append(0)
				n-=1
			else:
				l2.append(1)
				m-=1
		else:
			if(m>0):
				l2.append(1)
				m-=1
			else:
				l2.append(0)
				n-=1
	else:
		if(l2[i-1] == 0):
			if(m>0):
				l2.append(1)
				m-=1
			else:
				l2.append(0)
				n-=1
		else:
			if(n>0):
				l2.append(0)
				n-=1
			else:
				l2.append(1)
				m-=1
n= n1
m = m1
for i in range(1,n+m):
	if(l2[i] == l2[i-1]):
		q1+=1
	else:
		q2+=1
p1 = max(p1,q1)
p2 = m+n-1-p1
print(p1,p2)