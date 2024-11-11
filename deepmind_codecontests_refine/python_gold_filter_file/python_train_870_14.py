n=int(input())
a=list(map(int,input().split()))
m=int(input())
l=[]
for i in range(m):
	k=list(map(int,input().split()))
	l.append(k)
if n==1 and m!=0:
	print(0)
else:
	for i in range(m):
		if l[i][0]-1==0:
			a[l[i][0]]+= a[l[i][0]-1]-l[i][1]
			a[l[i][0]-1]=0
		elif l[i][0]-1==n-1:
			a[l[i][0]-2]+=l[i][1]-1		
			a[l[i][0]-1]=0
		else:	
			a[l[i][0]]+= a[l[i][0]-1]-l[i][1]
			a[l[i][0]-2]+=l[i][1]-1
			a[l[i][0]-1]=0
	for i in range(len(a)):
		print(a[i])