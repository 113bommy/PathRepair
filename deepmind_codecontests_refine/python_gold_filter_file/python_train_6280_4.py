t=int(input())
for i in range (t):
	t=input().split()
	n=int(t[0])
	a=int(t[1])
	b=int(t[2])
	s=input()
	if b>=0:
		print(n*a+n*b)
	else:
		k=1
		for i in range (n-1):
			if s[i]!=s[i+1]:
				k+=1
		print(n*a+(k//2+1)*b)