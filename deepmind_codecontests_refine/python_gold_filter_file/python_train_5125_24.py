t=int(input())
while t>0:
	t-=1
	n,d=map(int,input().split())
	a=list(map(int,input().split()))
	cnt=0
	for i in range(1,n):
		while d-i>=0 and a[i]>0:
			a[0]+=1
			d=d-(i)
			a[i]-=1
			#print(a[0],d,a[i])
	print(a[0])

