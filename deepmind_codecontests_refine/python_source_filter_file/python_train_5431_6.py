import math as m
a=[]
p=[]
q=[]
for i in range(int(input())):
	x=float(input())
	if i%2:
		y=m.ceil(x)
		if y!=x:
			p.append(i)
	else:
		y=m.floor(x)
		if y!=x:
			q.append(i)
	a.append(y)
print(a)
s=sum(a)
if s>0:
	j=0
	while s:
		a[p[j]]-=1
		j+=1
		s-=1
elif s<0:
	j=0
	while s:
		a[q[j]]+=1
		j+=1
		s+=1
for i in range(len(a)):
	print(a[i])