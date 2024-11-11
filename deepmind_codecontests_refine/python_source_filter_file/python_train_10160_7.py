n,m,k,t=list(map(int,input().split()))
karr=[list(map(int,input().split())) for _ in range(k)]
tarr=[list(map(int,input().split())) for _ in range(t)]
karr=[m*(x-1)+y for x,y in karr]
tarr=[m*(x-1)+y for x,y in tarr]
karr.sort()
mx=karr[-1]
a=['Carrots','Kiwis','Grapes']
#print(karr,tarr)
for q in tarr:
	if q>mx:
		print(a[(q-1+k)%3])
	else:
		count=0
		hit=False
		for i in range(k):
			if q<karr[i]:
				count=i
				break
			elif q==karr[i]:
				hit=True
				break
		if hit:
			print("Waste")
		else:
			print(a[((q-1)-count)%3])
