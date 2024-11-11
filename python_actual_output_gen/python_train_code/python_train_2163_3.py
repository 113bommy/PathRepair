t=int(input())
for i in range(0,t):
	L=list(map(int,input().split()))
	s=str(input())
	l=L[0]
	a=L[1]
	b=L[2]
	if(b>=0 or l==1):
		print((a+b)*l)
	else:
		ctr=0
		s+='2'
		for j in range(1,l+1):
			if(s[j]!=s[j-1]):
				ctr+=1
		#print(ctr)

		turns=(ctr+1)//2
		ans=a*l+b*turns
		print(ans)
