t=int(input())
for _ in range(t):
	
	s=input()
	oc=0
	zc=0
	first=-1

	for i in range(len(s)):
		if (s[i]=='0'):
			zc+=1
			if (first==-1):
				first=0
		else:
			oc+=1
			if (first==-1):
				first=1

	n=len(s)
	if (zc==n or oc==n):
		print(s)
	else:
		ma=max(zc,oc)
		if (first==0):
			st='01'
		else:
			st='10'
		str=''
		for i in range(ma):
			str+=st

		print(str)