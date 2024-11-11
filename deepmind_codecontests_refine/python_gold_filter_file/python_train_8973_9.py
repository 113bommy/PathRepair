for nt in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	a1=a[0:n][::-1]
	a2=a[n:]
	diff=0
	for i in a:
		if i==1:
			diff+=1
		else:
			diff-=1
	if diff==0:
		print (0)
		continue
	minn2={0:0}
	minn1={0:0}
	d1,d2=0,0
	for i in range(n):
		if a2[i]==1:
			d2+=1
		else:
			d2-=1
		if d2 not in minn2:
			minn2[d2]=i+1
		if a1[i]==1:
			d1+=1
		else:
			d1-=1
		if d1 not in minn1:
			minn1[d1]=i+1
	ans=2*n
	# print (diff)
	# print (minn1)
	# print (minn2)
	for i in range(-n,n+1):
		if i in minn1 and (diff-i) in minn2:
			ans=min(ans,minn1[i]+minn2[diff-i])
			# print (i,minn2[diff-i])
	print (ans)