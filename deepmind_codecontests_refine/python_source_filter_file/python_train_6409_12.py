import sys
import bisect
while True:
	try:
		n,m,k=[int(i) for i in input().split()]
		x,s=[int(i) for i in input().split()]
		ans=x*n
		a=[int(i) for i in input().split()]
		b=[int(i) for i in input().split()]
		c=[int(i) for i in input().split()]
		d=[int(i) for i in input().split()]
		a.append(x)
		b.append(0)
		for i in range(m):
			if b[i]>s:
				continue
			if s-b[i]<d[0]:
				ans=min(ans,a[i]*n)
				continue
			t=bisect.bisect_right(d,s-b[i])-1
			ans=min(ans,(n-c[t])*a[i]) 
		print(ans)	
		
	except EOFError:
		break