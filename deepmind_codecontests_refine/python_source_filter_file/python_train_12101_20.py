t=int(input())
for _ in range(t):
	n,k=map(int,input().split())
	pt=n
	n=k
	# lis=list(map(int,input().split()))
	c=1
	while(n-c>0):
		n-=c
		c+=1
	print(n,c)
	s="a"*pt
	if n==1:
		# c-=1
		loc1=pt-c-1
		s=s[:loc1]+"b"+s[loc1+1:]
		s=s[:-1]+"b"
		print(s)
		continue
	loc1=pt-c-1
	s=s[:loc1]+"b"+s[loc1+1:]
	k=pt-n
	s=s[:k]+"b"+s[k+1:]
	print(s)
