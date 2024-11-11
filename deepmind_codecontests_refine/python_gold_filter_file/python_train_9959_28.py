n,w=map(int,input().split())

alist=list(map(int,input().split()))

prefixsum=[0,alist[0]]

for i in range(1,n):
	prefixsum.append(prefixsum[-1]+alist[i])

minn=min(prefixsum)
maxx=max(prefixsum)

if maxx>w or maxx-minn>w:
	print(0)

else:	
	
	if minn<0:
		if abs(minn)>w:
			print(0)
		else:
			for i in range(n+1):
				prefixsum[i]+=abs(minn)
			maxx=max(prefixsum)
			print(w-maxx+1)
	else:
		maxx=max(prefixsum)
		print(w-maxx+1)


