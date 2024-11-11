n,k=map(int,input().strip().split())
l=list(map(int,input().split()))
k=min(l)
count=0
for x in l:
	x-=k
	if x%k!=0:
		print('-1')
		break
	if x%k==0:count+=x//k
else:print(count)