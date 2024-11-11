n,k=map(int,input().split())

l,r=1,n
while l<r:
	m=(l+r)//2
	s=(m*(m+1))//2
	rem=n-m
	print(rem,m,s)
	if s-rem==k:
		print(rem)
		exit()
	elif s-rem>k:
		r=m
	else:
		l=m
	if r-l==1:
		break
s=(l*(l+1))//2
rem =n-1
if s-rem==k:
	print(rem)
	exit()
rem=n-r
print(rem)

