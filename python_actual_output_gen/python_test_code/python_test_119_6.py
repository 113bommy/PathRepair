n,t=map(int,input().split())
l=[]
for i in range(n):
	s,d=map(int,input().split())
	s=s-t
	if(s<0):
		s=(s%d)
	l.append(s)
print(l)
print(l.index(min(l))+1)