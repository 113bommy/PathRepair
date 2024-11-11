for _ in range(int(input())):
	n,p,k=map(int,input().split())
	l=list(map(int,input().split()))
	l.sort()
	count=0
	s=p
	for i in range(1,n,2):
		if l[i]<=p:
			count+=2
			p-=l[i]
		else:
			if l[i-1]<=s:
				count+=1
			break
	count1=0
	if s>=l[0]:
		s-=l[0]
		count1+=1
	for i in range(2,n,2):
		if l[i]<=s:
			count1+=2
			s-=l[i]
		else:
			if l[i-1]<=s:
				count1+=1
			break
	print(max(count1,count))