a,b,c=map(int,input().split())
l=list(map(int,input().split()))
l1=list(map(int,input().split()))
s=[]
for i in range(a):
	s+=[list(map(int,input().split()))]

for i in range(a):
	for j in range(b):
		if s[i][j]==1:
			s[i][j]=min(l[j],l1[i])
for i in range(a):
	for j in range(b):
		print(s[i][j],end=" ")
	print()
