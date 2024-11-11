from math import ceil as c
n=int(input())
for i in range(n):
	k=int(input())
	s=list(map(ord,input()))
	l=c(k/2)
	for i in range(l):
		if s[i]==s[k-1-i] or abs(s[i]-s[k-1-i])==2:
			flag=0
		else:
			flag=1
			break
	if flag==0:
		print('YES')
	else:
		print('N0')