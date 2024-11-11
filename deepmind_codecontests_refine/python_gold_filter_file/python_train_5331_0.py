from collections import defaultdict
d=defaultdict(list)
n,m=map(int,input().split())
for i in range(m):
	l=list(map(int,input().split()))
	for j in range(len(l)-1):
		d[j].append((l[-1]-l[j],i))
ind=[i+1 for i in range(m)]
minl=m
for j in range(n-1):
	temp=[]
	d[j].sort(reverse=True)
	s=0
	for p in range(len(d[j])):
		s+=d[j][p][0] 
	k=-1
	while(s>0):
		k+=1
		s-=d[j][k][0]
		temp.append(d[j][k][1]+1)
	if len(temp)<minl:
		ind=temp
		minl=len(temp)
print(len(ind))
print(*ind)
