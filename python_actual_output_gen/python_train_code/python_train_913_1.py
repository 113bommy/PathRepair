n,m=[int(x) for x in input().split()]
if m%n!=0:
	print(-1)
else:
	ans=0
	fact = m//n
	while fact:
		if fact==1:
			break
		elif fact%2==0:
			fact/=2
			ans+=1
		elif fact%3==0:
			fact/=3
			ans+=1
		else:
			ans=0
			break
	print(ans)