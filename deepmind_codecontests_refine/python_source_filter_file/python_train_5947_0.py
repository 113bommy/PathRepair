n=int(input())
s=input()
x=set(s)
if len(x)>1:
	print('YES')
	for i in range(n-1):
		if s[i]!=s[i+1]:
			print(s[i:i+2])
		break
else:
	print('NO')