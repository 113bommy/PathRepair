n=int(input())
a=list(map(int,input().split()))
m=int(input())
l=[]
for i in range(m):
	x,y=map(int,input().split())
	l.append([x-1,y])
for i in range(m):
	if(l[i][0]==n-1):
		a[l[i][0]-1]=a[l[i][0]-1]+(l[i][1]-1)
		a[l[i][0]]=0
	elif(l[i][0]==0):
		a[l[i][0]+1]=a[l[i][0]+1]+(a[l[i][0]]-l[i][1])
		a[l[i][0]]=0
	else:
		a[l[i][0]+1]=a[l[i][0]+1]+(a[l[i][0]]-l[i][1])
		a[l[i][0]-1]=a[l[i][0]-1]+(l[i][1]-1)
		a[l[i][0]]=0
for i in range(len(a)):
	print(a[i])
