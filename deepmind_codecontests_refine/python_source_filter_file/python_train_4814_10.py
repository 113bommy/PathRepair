import bisect
for _ in range(int(input())):
	n,x=map(int,input().split())
	a=list(map(int,input().split()))
	a.sort()
	s=sum(a)
	t=0
	k=n
	for i in range(n):
		if ((s-t)//x)==n-i:
			k=i
			break
		t+=a[i]
	print(n-k)
