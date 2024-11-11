for _ in range(int(input())):
	n,k=list(map(int,input().split()))
	s=sorted(list(input()))
	if s[k-1]!=s[0] or n==k:print(s[k-1])
	elif s[k]!=s[-1]:print(s[0]+''.join(s[k:]))
	else:print(s[0]+s[-1]*(((n-k)//k)+(1 if (n-k)%k!=0 else 0)))