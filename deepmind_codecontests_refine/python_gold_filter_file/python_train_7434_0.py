l1=input()
l1=l1.split()
n=int(l1[0])
d=int(l1[1])
l=input()
l=l.split()
a=[]
s=0
for i in range(n):
	a.append(int(l[i]))
	s+=int(l[i])
m=int(input())
if(m>=n):
	print(s-((m-n)*d))
else:
	a.sort()
	s=0
	i=0
	while m>0:
		m-=1
		s+=a[i]
		a.remove(a[i])
	print(s)