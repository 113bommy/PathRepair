n,k=map(int,input().split(" "))
a=[int(i) for i in input().split(" ")][:n]
a.sort()
m=dict()
removed=dict()
for i in range(n):
	m[a[i]]=int(1)
count=int(n)
for i in range(n) :
	if(removed.get(a[i],0)==0):
		if(m.get(a[i]*k,-1)==1):
			removed[(a[i]*k)]=1
			count-=1
print(count)
