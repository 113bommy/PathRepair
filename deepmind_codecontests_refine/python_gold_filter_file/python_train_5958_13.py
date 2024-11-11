


for _ in range(int(input())):
	n,g,b=map(int,input().split())

	low=0
	high=10**20
	ans=-1

	tot=g+b

	while(low<=high):
		mid=(low+high)//2

		now=mid//tot
		md=mid%tot

		gn=now*g
		gn+=min(g,md)

		nt=now*b
		md-=g

		if(md>0):
			nt+=md
		nt+=gn

		if(2*gn>=n and nt>=n):
			ans=mid
			high=mid-1
		else:
			low=mid+1

	print(ans)
