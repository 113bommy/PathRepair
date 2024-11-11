n=int(input())
for i in range(n):
	s1=int(input())
	s2=list(map(int,input().split()))
	p=1
	s=0
	count=0
	for i in range(s1):
		s=s+s2[i]
		p=p*s2[i]
		if p==0:
			if s2[i]==0:
				s2[i]=s2[i]+1
				count+=1
				s+=count
	if s == 0:
		# s2[0]=s2[0]+1
		print(count+1)
	else:
		print(count)
	# print(s2)