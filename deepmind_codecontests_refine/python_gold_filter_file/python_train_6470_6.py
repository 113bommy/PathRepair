#https://codeforces.com/problemset/problem/1155/B
n=int(input())
s=input()
if n<11:
	print('NO')
elif n==11:
	if s[0]=='8':
		print('YES')
	else:
		print('NO')
else:
	if s[:-10].count('8') <= (n-11)//2:
		print('NO')
	else:
		print('YES')
