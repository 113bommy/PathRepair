n = int(input())
s = ''
if n//2+n%2>17: print(-1)
else:
	for i in range(n//2):
		print(8,end='')
	for i in range(n%2):
		print(4)