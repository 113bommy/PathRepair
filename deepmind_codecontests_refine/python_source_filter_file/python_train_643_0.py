a,sx,sy=map(int,input().split())
xy=[]
for i in range(a):
	xy.append(tuple(map(int,input().split())))
c=0
c1=0
p=0
p1=0
ar=[0,0,0,0]
for i in xy:
	if(i[0]>sx):
		ar[0]+=1
	if(i[1]>sy):
		ar[1]+=1
	if(i[0]<sx):
		ar[2]+=1
	if(i[0]<sy):
		ar[3]+=1
ar=list(enumerate(ar))
z=sorted(ar,reverse=True,key=lambda x:x[1])
if(z[0][0]==0):
	print(ar[0][1])
	print(sx+1,sy)
elif(z[0][0]==1):
	print(ar[1][1])
	print(sx,sy+1)
elif(z[0][0]==2):
	print(ar[2][1])
	print(sx-1,sy)
elif(z[0][0]==3):
	print(ar[3][1])
	print(sx,sy-1)