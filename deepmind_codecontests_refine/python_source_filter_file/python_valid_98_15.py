for _ in range(int(input())):
	n=int(input())
	s=input()
	l=list(s)
	charset=set(l)
	if len(charset)==1:
		print(-1,-1)
	else:
		for i in range(n-1):
			if l[i]!=l[i+1]:
				print(i,i+1)
				break