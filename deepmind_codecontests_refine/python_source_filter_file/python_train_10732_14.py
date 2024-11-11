n,m=map(int,input().split())
s=input()
t=input()
if m<n:
	print('NO')
else:
	if '*' not in s:
		if s==t:
			print('YES')
		else:
			print('NO')
	else:
		if s[0]=='*':
			s1=s[1:]
			t1=t[m-n+1:]
			if s1==t1:
				print('YES')
			else:
				print('NO')
		elif s[n-1]=='*':
			s1=s[:n-1]
			t1=t[:n-1]
			if s1==t1:
				print('YES')
			else:
				print('NO')
		else:
			index=s.find('*')
			s1=s[:index]+s[index+1:]
			temp=n-index
			t1=t[:index]+t[m-temp+1:]
			if s1==t1:
				print('YES')
			else:
				print('NO')