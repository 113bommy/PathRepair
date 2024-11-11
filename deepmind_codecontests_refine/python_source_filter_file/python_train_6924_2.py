n,m =map(int, input().split())
#b=[]
d=[0]*n
f=[[] for i in range(n)]
#for i in range(n):
#	f+=[]
#print(f)
#print(d)
for i in range(m):
	#s=input().split()
	a=list(map(int, input().split()))
	d[a[0]-1]+=1
	d[a[1]-1]+=1
	a.sort
	#a.reverse
	f[a[1]-1]+=[a[0]-1]

#print(f[4])
k=[1]*n
res = 0
for i in range(n):
	for j in f[i]:
		k[i]=max(k[i], k[j]+1)
	res = max(res, k[i]*d[i])	
	
#	print(f)
	
print(res)
#b.sort
#print(b)# your code goes here# your code goes here