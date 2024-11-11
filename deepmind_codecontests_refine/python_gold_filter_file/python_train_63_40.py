
n,k=map(int,input().split())
l=list(map(int,input().split()))
k2=[]
l.sort()
for i in range(n):
	if k%l[i]==0:
		k2.append(l[i])

print(k//k2[-1])