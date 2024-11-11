n,m=map(int,input().split()) 	 
l=[]
for j in range(n):
	l.append(list(map(int,input().split())))
r=[]
k=0
for j in range(len(l)):
	if l[j][0]==1:
		k=k+1
	if l[j][-1]==1:
		k=k+1
if 1 in l[0]:
	k=k+1
if 1 in l[n-1]:
	k=k+1
if(k>0):
	print(2)
else:
	print(4)