g=input()
n,k=[int(x) for x in g.split()]
r=input()
li=[]
for y in r.split():
	li.append(int(y))
m=max(li)
t=min(li)
if m-t>k:
	print("NO")
else:
	print("YES")
	for i in range(n):
		lis=[]
		u=li[i]
		jai=int(u/k)
		veer=u%k
		while jai>0:
			for i in range(n):
				lis.append(i+1)
			jai-=1

		for ihj in range(veer):
			lis.append(ihj+1)
		lis=sorted(lis)	
		print(' '.join(map(str, lis)))	

