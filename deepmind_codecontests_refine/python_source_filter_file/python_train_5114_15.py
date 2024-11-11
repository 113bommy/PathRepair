n=int(input())
a=[int(i) for i in input().split()]

zs=[]

for x in range(1,len(a)-1):
	if(a[x-1]==1 and a[x]==0 and a[x+1]==1):
		zs.append(x)

if(len(zs)==1):
	print(1)
else:
	ans=len(zs)
	for q in range(len(zs)-1):
		if(zs[q]>0 and zs[q+1]-zs[q]==2):
			ans-=1
			zs[q]=-zs[q]
	print(ans)