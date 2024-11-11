t=int(input())
 
while(t):
	n,m=input().split()
	n=int(n)
	m=int(m)
 
	a = [int(a) for a in input().split()]
	p = [int(p) for p in input().split()] 
	p.sort()
	a1=sorted(a)
	left=p[0]-1

	for i in range(1,m):
		if p[i]-p[i-1]>1:
			right=p[i-1]+1
			a[left:right]=sorted(a[left:right])
			left=p[i]-1

	right=p[m-1]+1
	a[left:right]=sorted(a[left:right])
	print(a)

	if a1==a:
		print("YES")
	else:
		print("NO")

	t=t-1