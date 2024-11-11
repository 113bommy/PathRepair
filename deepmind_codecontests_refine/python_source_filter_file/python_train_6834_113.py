n=int(input())
if n<=36:
	print (int('8'*(n//2) + '0'*(n%2)))
else:
	print(-1)