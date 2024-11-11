n,k=map(int,input().split())
t=240-k
count=0
ts=0
for i in  range(1,n+1):
	t1=5*i
	t-=t1
	if t>0:
		count+=1
print(count)
