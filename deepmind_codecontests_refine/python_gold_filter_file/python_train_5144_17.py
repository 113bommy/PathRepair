n,m=map(int,input().split())
a=[int(i) for i in input().split()]
res=0
tmp=[]

for i in range(n):
	if a[i]<0 and len(tmp)<m:
		res-=a[i]
		tmp.append(a[i])
	elif len(tmp)==m and a[i]<max(tmp):
		res+=max(tmp)-a[i]
		tmp.remove(max(tmp))
		tmp.append(a[i])
print(res)


		
