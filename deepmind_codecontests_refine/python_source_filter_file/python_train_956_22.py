n,m,d=map(int,input().split())
c=list(map(int,input().split()))
nl=n
for i in c:
	nl-=(i-1)
a=[0]*nl
#print(a)
no0 = nl-d

dr=m
pos = nl-(d-1)-1

while(dr < (pos+1) and dr>0):
	#print(dr,pos)
	a[pos] = dr
	dr-=1
	pos-=(d)

#print(dr,pos)
while(dr>0):
	a[dr-1]=dr
	dr-=1

pos1=-1
for i in range (nl):
	if(a[i]==1):
		pos1=i

if(pos1 > d):
	print("NO")

else:
	print("YES")
	for i in range (nl):
		if(a[i]!=0):
			for j in range (c[a[i]-1]):
				print(a[i],end=" ")

		else:
			print("0",end=" ")

	print()


	







