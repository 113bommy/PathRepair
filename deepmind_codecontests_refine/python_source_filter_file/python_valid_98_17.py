t=int(input())
for _ in range(t):
	n=int(input())
	s=input()
	flag=False
	pos=-1
	for i in range(n-1):
		if(s[i]!=s[i+1]):
			pos=i
			flag=True
			break
	if(flag):
		print(pos,pos+1)
	else:
		print(-1,-1)