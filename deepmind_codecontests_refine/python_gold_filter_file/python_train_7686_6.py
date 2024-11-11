from heapq import*
n=int(input())
a=[-int(e)for e in input().split()]
r=0
heapify(a)
while 1:
	x=heappop(a)
	if x>-n:break
	c=-x//n
	x+=c*n
	for i in range(n-1):a[i]-=c
	heappush(a,x)
	r+=c
print(r)