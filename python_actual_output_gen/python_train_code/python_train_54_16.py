yo=list(map(int,input().split()))
n=yo[0]
c=yo[1]
x=list(map(int,input().split()))

maxdip=0
flag=0
#maxdipind=0
for i in range(1,n):
	if x[i-1]-x[i]>=maxdip:
		flag=1
		maxdip=x[i-1]-x[i]
		#print(maxdip)
		#maxdipind=[i]
ans=maxdip-c
if flag==0:
	print(0)
else:


	print(ans)		